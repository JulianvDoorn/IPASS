#include "rgb_matrix.hpp"

void rgb_matrix::write_implementation(hwlib::location l, hwlib::color c, hwlib::buffering buf = hwlib::buffering::unbuffered) {
	c = hwlib::color(c.red, c.green, c.blue);
	
	if (l.y < 8) {
		top.write(l, c);
	} else if (l.y  < 16) {
		bottom.write(l - hwlib::location(0, 8), c);
	}
}

void rgb_matrix::show_frame() {
	for (uint_fast16_t i = 0; i < drawings_c; i++) {
		drawings[i]->draw(*this);
	}
	
	for (uint_fast8_t c = 1; c <= 4; c++) {
		for (uint_fast8_t y = 0; y < 8; y++) {
			port.output_enabled.set(0);

			for (uint_fast8_t x = 0; x < 32; x++) {
				uint_fast8_t r = top.pixels[y][x].red;
				uint_fast8_t g = top.pixels[y][x].green;
				uint_fast8_t b = top.pixels[y][x].blue;
				uint_fast8_t rgb = (r >= c) << 2 | (g >= c) << 1 | (b >= c);
				top.emit(rgb);

				r = bottom.pixels[y][x].red;
				g = bottom.pixels[y][x].green;
				b = bottom.pixels[y][x].blue;
				rgb = (r >= c) << 2 | (g >= c) << 1 | (b >= c);

				bottom.emit(rgb);

				port.clock.set(0);
				port.clock.set(1);
			}

			port.output_enabled.set(1);
			port.address.set(y);
			port.latch.set(1);
			port.latch.set(0);
		}
	}
}

void rgb_matrix::loop() {
	for (;;) {
		show_frame();
	}
}

void rgb_matrix::flush() {}

void rgb_matrix::clear(hwlib::buffering buf) {
	for (uint_fast8_t y = 0; y < size.y; y++) {
		for (uint_fast8_t x = 0; x < size.x; x++) {
			write_implementation(hwlib::location(x, y), background);
		}
	}
}