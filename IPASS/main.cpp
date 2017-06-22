//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <hwlib.hpp>

#include "rainbow.hpp"
#include "rainbow_text_label.hpp"
#include "rgb_matrix.hpp"
#include "rgb_pins.hpp"
#include "text_slide.hpp"
#include "updating_text_slide.hpp"

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

	auto f = hwlib::font_default_8x8();
	auto rainbow_f = rainbow_text_label("bier", hwlib::location(0, 0), f);
	auto rainbow_sliding = updating_text_slide(rainbow_f);
	my_window << rainbow_sliding;

	auto text_l = text_label("hier", hwlib::location(0, 8), f);
	my_window << text_l;

	hwlib::location offset = hwlib::location(0, 0);

	while (true) {
		static uint_fast8_t b = 0;

		if (b == 4) {
			offset = offset + hwlib::location(1, 0);
			rainbow_sliding.offset = offset;
			b = 0;
		}

		b++;

		if (offset.x >= 32) {
			offset = hwlib::location(0, 0);
			rainbow_sliding.offset = offset;
		}

		my_window.show_frame();
	}
}