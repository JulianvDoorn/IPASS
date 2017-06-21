#pragma once
#include "image_invert.hpp"
#include "image_rainbow.hpp"
#include "text_label.hpp"
#include "updating_text_label.hpp"
#include <hwlib.hpp>

class rainbow_text_label : public updating_text_label {
	uint_fast8_t iteration = 0;
	uint_fast8_t color_offset = 0;

	void draw_implementation(hwlib::window& w, const hwlib::image& letter, hwlib::location l_pos, hwlib::buffering buf) const override {
		const image_invert img = image_invert(letter);
		const image_rainbow rainbow_img = image_rainbow(img, color_offset);

		w.write(l_pos, rainbow_img);
	}

	public:
	rainbow_text_label(const char* text, hwlib::location pos, hwlib::font& f) : updating_text_label(text, pos, f) {}

	void update() override {
		iteration++;

		if (iteration >= 3) {
			color_offset++;
			color_offset %= 14;
			iteration = 0;
		}
	}
};