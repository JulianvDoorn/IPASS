#include <hwlib-wait.hpp>
#include <hwlib.hpp>

#include "rgb_matrix.hpp"
#include "rgb_pins.hpp"

int main() {
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;

	hwlib::wait_ms(1000);
	hwlib::cout << "Started" << hwlib::endl;

	auto r0 = hwlib::target::pin_out(hwlib::target::pins::d52);
	auto g0 = hwlib::target::pin_out(hwlib::target::pins::d50);
	auto b0 = hwlib::target::pin_out(hwlib::target::pins::d48);
	rgb_pins rgb0 = rgb_pins(r0, g0, b0);

	auto r1 = hwlib::target::pin_out(hwlib::target::pins::d53);
	auto g1 = hwlib::target::pin_out(hwlib::target::pins::d51);
	auto b1 = hwlib::target::pin_out(hwlib::target::pins::d49);
	rgb_pins rgb1 = rgb_pins(r1, g1, b1);

	auto a0 = hwlib::target::pin_out(hwlib::target::pins::d46);
	auto a1 = hwlib::target::pin_out(hwlib::target::pins::d44);
	auto a2 = hwlib::target::pin_out(hwlib::target::pins::d42);
	auto my_address_port = hwlib::port_out_from_pins(a0, a1, a2);

	auto clock = hwlib::target::pin_out(hwlib::target::pins::d47);
	auto latch = hwlib::target::pin_out(hwlib::target::pins::d45);
	auto output_enabled = hwlib::target::pin_out(hwlib::target::pins::d43);
	
	auto my_rgb_port = rgb_matrix_port(rgb0, rgb1, my_address_port, clock, latch, output_enabled);
	auto my_window = rgb_matrix(my_rgb_port);

	for (;;) {
		int rgb = 0;

		for (int y = 0; y < 16; y++) {
			for (int x = 0; x < 32; x++) {
				
				int r = rgb >> 4 & 0b11;
				int g = rgb >> 2 & 0b11;
				int b = rgb & 0b11;
				
//				hwlib:: cout << r << g << b << hwlib::endl;
				
				my_window.write(hwlib::location(x, y), hwlib::color(r, g, b));
				rgb++;
			}
		}

//		hwlib::cout << "la" << hwlib::endl;

		my_window.show_frame();
	}
}