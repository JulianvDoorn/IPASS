//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "defines.hpp"
#include "rgb_matrix.hpp"

void rgb_matrix::write_implementation(hwlib::location l, hwlib::color c, hwlib::buffering buf) {
	// downscales 8 bit color values to 2 bit color values due to PWM limitation
	// 2^8 represents the max value of an 8 bit value (256), I would've used UINT_FAST8_MAX but that value is 'only' 255
	// the formula (2^8 / 2^x) calculates a divider to downscale the color appropriately
	c = hwlib::color(c.red / (2 ^ 8 / 2 ^ pwm_color_bit_size), c.green / (2 ^ 8 / 2 ^ pwm_color_bit_size), c.blue / (2 ^ 8 / 2 ^ pwm_color_bit_size));

	if (l.y < 8) {
		top.write(l, c);
	} else if (l.y < 16) {
		bottom.write(l - hwlib::location(0, 8), c);
	}
}

void rgb_matrix::show_frame() {
	clear();
	update_all();
	draw_all();

	// Outermost loop for PWM cycles
	for (uint_fast8_t c = 1; c <= pwm_color_max_value; c++) {
		
		// Iterates over every row
		for (uint_fast8_t y = 0; y < 8; y++) {
			
			// Iterates over every pixel in a row
			for (uint_fast8_t x = 0; x < 32; x++) {
				// Sets the top half of the window
				uint_fast8_t r = top.pixels[y][x].red;
				uint_fast8_t g = top.pixels[y][x].green;
				uint_fast8_t b = top.pixels[y][x].blue;
				uint_fast8_t rgb = (r >= c) << 2 | (g >= c) << 1 | (b >= c);
				top.emit(rgb);

				// Sets the bottom half of the window
				r = bottom.pixels[y][x].red;
				g = bottom.pixels[y][x].green;
				b = bottom.pixels[y][x].blue;
				rgb = (r >= c) << 2 | (g >= c) << 1 | (b >= c);
				bottom.emit(rgb);

				// Clock pulse to tell matrix to select next pixel
				port.clock.set(0);
				port.clock.set(1);
			}

			port.output_enabled.set(1);
			port.address.set(y);
			port.latch.set(1);
			port.latch.set(0);
			port.output_enabled.set(0);
		}
	}
}

void rgb_matrix::loop() {
	for (;;) {
		show_frame();
	}
}

void rgb_matrix::clear(hwlib::buffering buf) {
	for (uint_fast8_t y = 0; y < size.y; y++) {
		for (uint_fast8_t x = 0; x < size.x; x++) {
			write_implementation(hwlib::location(x, y), background);
		}
	}
}