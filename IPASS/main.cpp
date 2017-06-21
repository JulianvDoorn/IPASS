#include <hwlib.hpp>

#include "rainbow_font.hpp"
#include "rgb_matrix.hpp"
#include "rgb_pins.hpp"
#include "rainbow.hpp"

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

	auto my_circle = hwlib::circle(hwlib::location(5, 5), 3, hwlib::blue, hwlib::black);
	auto my_line = hwlib::line(hwlib::location(0, 0), hwlib::location(0, 5), hwlib::red);

	//my_window << my_line;

	auto f = hwlib::font_default_8x8();

	//auto window_inverted = hwlib::window_invert(my_window);
	//hwlib::window_ostream window_out = hwlib::window_ostream(window_inverted, f);

	auto rainbow_f = rainbow_font("HELO", hwlib::location(0, 0), f);
	my_window << rainbow_f;
	
	auto rainbow_f1 = rainbow_font("WRLD", hwlib::location(0, 8), f);
	my_window << rainbow_f1;

	//animator << "Frik\nadel";
	//window_out << "Frik\nadel";

//	int i = 0;
	hwlib::location l = hwlib::location(0, 0);

	while (true) {
//		i++;
//		i %= 140;

		//hwlib::cout << i << ' ' << r << ' ' << g << ' ' << b << hwlib::endl;

		my_window.show_frame();

//		for (uint_fast8_t i = 0; i < 14; i++) {
//			for (uint_fast8_t x = 0; x < 32; x++) {
//				
//
//				for (uint_fast8_t y = 0; y < 16; y++) {
//					my_window.write(hwlib::location(x, y), rainbow[x % 14]);
//				}
//			}
//
//			my_window.show_frame();
//		}

		//		for (int i = 0; i < 32; i++) {
		//			my_window.write(l, hwlib::color(r, g, b));
		//
		//			if (l.x < 31) {
		//				l = l + hwlib::location(1, 0);
		//			} else if (l.y >= 15) {
		//				l = hwlib::location(0, 0);
		//			} else {
		//				l = hwlib::location(0, l.y + 1);
		//			}
		//		}
	}
}