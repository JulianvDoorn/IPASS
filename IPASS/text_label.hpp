//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include "image_invert.hpp"
#include <hwlib.hpp>

/**
 * @class text_label
 * @author Julian
 * @date 20/06/17
 * @file text_label.hpp
 * @brief This class is used for displaying text_labels on a hwlib::window instance
 */
class text_label : public hwlib::drawable {
	protected:
	const char* text;
	hwlib::location pos;
	hwlib::font& f;

	virtual void draw_implementation(hwlib::window& w, const hwlib::image& letter, const hwlib::location l_pos, hwlib::buffering buf);

	public:
	text_label(const char* text, hwlib::location pos, hwlib::font& f) : drawable(pos), text(text), pos(pos), f(f) {}

	void draw(hwlib::window& w, hwlib::buffering buf = hwlib::buffering::unbuffered);
};