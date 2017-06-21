//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include "image_invert.hpp"
#include "image_rainbow.hpp"
#include "updating_text_label.hpp"
#include <hwlib.hpp>

/**
 * @class rainbow_text_label
 * @author Julian
 * @date 20/06/17
 * @file rainbow_text_label.hpp
 * @brief text_label that has a rainbow effect over its text
 */
class rainbow_text_label : public updating_text_label {
	private:
	uint_fast8_t iteration = 0;
	uint_fast8_t color_offset = 0;

	void draw_implementation(hwlib::window& w, const hwlib::image& letter, hwlib::location l_pos, hwlib::buffering buf) override {
		const image_invert img = image_invert(letter);
		const image_rainbow rainbow_img = image_rainbow(img, color_offset);

		w.write(l_pos, rainbow_img);
	}

	public:
	rainbow_text_label(const char* text, hwlib::location pos, hwlib::font& f) : updating_text_label(text, pos, f) {}

	/**
	 * @copydoc updating_drawable::update
	 */
	void update() override {
		iteration++;

		if (iteration >= 3) {
			color_offset++;
			color_offset %= 14;
			iteration = 0;
		}
	}
};