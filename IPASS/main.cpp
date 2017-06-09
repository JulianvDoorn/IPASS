#include <hwlib-wait.hpp>
#include <hwlib.hpp>

#include "address_port.hpp"
#include "rgb_port.hpp"

namespace rgb_matrix {

void wait_half_period() {
	hwlib::wait_us(1);
}

class window_part {
	public:
	color pixels[8][32];

	rgb_port& rgb;

	window_part(rgb_port& rgb) : rgb(rgb) {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 32; x++) {
				pixels[y][x] = 0;
			}
		}
	}

	//	void set_pixel(location l) {
	//		rgb.set(pixels[l.y][l.x]);
	//	}

	void write_color(location l, color c) {
		pixels[l.y][l.x] = c;
	}

	void write(location l, char c) {
		//hwlib::cout << "Writing pixel " << l << hwlib::endl;
		//pixels[l.y][l.x] = c;
	}

	void clear() {
		rgb.set(0);
	}

	friend class window;
};

class bcm_controller {};

class window {
	window_part top_part;
	window_part bottom_part;

	address_port& address;
	pin_out& clock;
	pin_out& latch;
	pin_out& output_enabled;

	public:
	window(rgb_port& rgb0, rgb_port& rgb1, address_port& address, pin_out& clock, pin_out& latch, pin_out& output_enabled) : top_part(rgb0), bottom_part(rgb1), address(address), clock(clock), latch(latch), output_enabled(output_enabled) {}

	void write_color(location l, color c) {
		if (l.y < 8) {
			top_part.write_color(l, c);
		} else if (l.y < 16) {
			bottom_part.write_color(l - location(0, 8), c);
		}
	}

	void write(location l, char c) {
		if (l.y < 8) {
			top_part.write(l, c);
		} else if (l.y < 16) {
			bottom_part.write(l - location(0, 8), c);
		}
	}

	void flush() {
		for (int c = 0; c < 8; c++) {
			for (int y = 0; y < 8; y++) {
				output_enabled.set(0);
				wait_half_period();

				for (int x = 0; x < 32; x++) {
					char r = top_part.pixels[y][x].red >> c & 1;
					char g = top_part.pixels[y][x].green >> c & 1;
					char b = top_part.pixels[y][x].blue >> c & 1;
					char rgb = r << 2 | g << 1 | b;
					
					top_part.rgb.set(rgb);

					r = bottom_part.pixels[y][x].red >> c & 1;
					g = bottom_part.pixels[y][x].green >> c & 1;
					b = bottom_part.pixels[y][x].blue >> c & 1;
					rgb = r << 2 & g << 1 & b;
					
					bottom_part.rgb.set(rgb);

					//wait_us(1 * c);

					wait_half_period();
					clock.set(0);
					wait_half_period();
					clock.set(1);
					wait_half_period();
				}

				output_enabled.set(1);
				wait_half_period();
				address.set(y);
				wait_half_period();
				latch.set(1);
				wait_half_period();
				latch.set(0);
				wait_half_period();
			}
		}
	}
};

} // my_namespace

int main() {
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;

	hwlib::wait_ms(1000);
	hwlib::cout << "Started" << hwlib::endl;

	auto r0 = hwlib::target::pin_out(hwlib::target::pins::d53);
	auto g0 = hwlib::target::pin_out(hwlib::target::pins::d51);
	auto b0 = hwlib::target::pin_out(hwlib::target::pins::d49);
	rgb_port rgb0 = rgb_port(r0, g0, b0);

	auto r1 = hwlib::target::pin_out(hwlib::target::pins::d52);
	auto g1 = hwlib::target::pin_out(hwlib::target::pins::d50);
	auto b1 = hwlib::target::pin_out(hwlib::target::pins::d48);
	rgb_port rgb1 = rgb_port(r1, g1, b1);

	auto a0 = hwlib::target::pin_out(hwlib::target::pins::d47);
	auto a1 = hwlib::target::pin_out(hwlib::target::pins::d45);
	auto a2 = hwlib::target::pin_out(hwlib::target::pins::d43);
	address_port my_address_port = address_port(a0, a1, a2);

	auto clock = hwlib::target::pin_out(hwlib::target::pins::d46);
	auto latch = hwlib::target::pin_out(hwlib::target::pins::d44);
	auto output_enabled = hwlib::target::pin_out(hwlib::target::pins::d42);
	auto my_window = rgb_matrix::window(rgb0, rgb1, my_address_port, clock, latch, output_enabled);

	for (;;) {
		my_window.write_color(location(1, 1), color(0x21, 0x15, 0x30));

		my_window.flush();

		wait_ms(0);
	}
}