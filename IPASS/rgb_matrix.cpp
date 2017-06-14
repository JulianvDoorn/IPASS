#include "rgb_matrix.hpp"

void rgb_matrix::show_frame() {
//	hwlib::cout << "show frame" << hwlib::endl;
	for (uint_fast8_t c = 1; c <= 4; c++) {
//		hwlib::cout << "show frame"  << c << hwlib::endl;
		for (uint_fast8_t y = 0; y < 8; y++) {
			port.output_enabled.set(0);
//			hwlib::cout << "oof? Y:"   << y << hwlib::endl;

			for (uint_fast8_t x = 0; x < 32; x++) {
//				hwlib::cout << "oof? X:"   << x << hwlib::endl;
				uint_fast8_t r = top.pixels[y][x].red;
				uint_fast8_t g = top.pixels[y][x].green;
				uint_fast8_t b = top.pixels[y][x].blue;
//				hwlib::cout << "oof? X:"   << x << hwlib::endl;
				uint_fast8_t rgb = (r >= c) << 2 | (g >= c) << 1 | (b >= c);
//				hwlib::cout << "oof? RGB:"   << rgb << hwlib::endl;
				top.emit(rgb);
//				hwlib::cout << "did I set RGB?" << hwlib::endl;
				

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

void rgb_matrix::write(hwlib::location pos, hwlib::color col, hwlib::buffering buf) {
	if (pos.y < 8) {
		top.write(pos, col);
	} else if (pos.y  < 16) {
		bottom.write(pos - hwlib::location(0, 8), col);
	}
}

void rgb_matrix::write(hwlib::location pos, const hwlib::image& img, hwlib::buffering buf) {}

void rgb_matrix::write(hwlib::location pos, hwlib::buffering buf) {
	write(pos, foreground);
}

void rgb_matrix::clear(hwlib::buffering buf) {
	
}