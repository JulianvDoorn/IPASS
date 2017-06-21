#include "text_label.hpp"

void text_label::draw_implementation(hwlib::window& w, const hwlib::image& letter, const hwlib::location l_pos, hwlib::buffering buf) {
	const image_invert img = image_invert(letter);
	w.write(l_pos, img);
}

void text_label::draw(hwlib::window& w, hwlib::buffering buf = hwlib::buffering::unbuffered) {
	hwlib::location f_size = f[' '].size;
	uint_fast8_t row = 0;
	uint_fast8_t column = 0;

	for (int i = 0; text[i] != '\0'; i++) {
		char c = text[i];

		if (c == '\n') {
			row++;
			column = 0;
		} else {
			draw_implementation(w, f[c], pos + hwlib::location(column * f_size.x, row * f_size.y), buf);
			column++;
		}
	}
}