#pragma once
#include "image_invert.hpp"
#include <hwlib.hpp>

class text_label : public hwlib::drawable {
	protected:
	const char* text;
	hwlib::location pos;
	const hwlib::font& f;

	virtual void draw_implementation(hwlib::window& w, const hwlib::image& letter, const hwlib::location l_pos, const hwlib::buffering buf) const {
		const image_invert img = image_invert(letter);
		w.write(l_pos, img);
	}

	public:
	text_label(const char* text, hwlib::location pos, const hwlib::font& f) : drawable(pos), text(text), pos(pos), f(f) {}

	void draw(hwlib::window& w, const hwlib::buffering buf = hwlib::buffering::unbuffered) const {
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
};