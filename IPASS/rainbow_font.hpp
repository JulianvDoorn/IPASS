#pragma once
#include "image_invert.hpp"
#include "image_rainbow.hpp"
#include "updating_drawable.hpp"
#include <hwlib.hpp>

class rainbow_font : public updating_drawable {
	uint_fast8_t iteration = 0;
	uint_fast8_t color_offset = 0;

	const char* text;
	hwlib::location pos;
	hwlib::font& f;

	public:
	rainbow_font(const char* text, hwlib::location pos, hwlib::font& f) : updating_drawable(pos), text(text), pos(pos), f(f) {}

	void draw(hwlib::window& w, hwlib::buffering buf = hwlib::buffering::unbuffered) override {
		for (int i = 0; text[i] != '\0'; i++) {
			char c = text[i];

			const image_invert img = image_invert(f[c]);
			const image_rainbow rainbow_img = image_rainbow(img, color_offset);
			
			w.write(pos + hwlib::location(f[' '].size.x * i, 0), rainbow_img);
		}
	}

	void update() override {
		iteration++;

		if (iteration >= 3) {
			color_offset++;
			color_offset %= 14;
			iteration = 0;
		}
	}
};