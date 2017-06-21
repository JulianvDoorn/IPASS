#include "rainbow_text_label.hpp"

void rainbow_text_label::draw_implementation(hwlib::window& w, const hwlib::image& letter, hwlib::location l_pos, hwlib::buffering buf) {
	const image_invert img = image_invert(letter);
	const image_rainbow rainbow_img = image_rainbow(img, color_offset);

	w.write(l_pos, rainbow_img);
}

void rainbow_text_label::update() {
	iteration++;

	if (iteration >= 3) {
		color_offset++;
		color_offset %= 14;
		iteration = 0;
	}
}