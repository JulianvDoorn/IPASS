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
	/**
	 * @brief Construcsts a text_label with the given arguments
	 * @param text Text to display
	 * @param pos Position to display at
	 * @param f Font to display with
	 */
	text_label(const char* text, hwlib::location pos, hwlib::font& f) : drawable(pos), text(text), pos(pos), f(f) {}

	/**
	 * @brief Draws the text
	 * @param w Window to draw the text to
	 * @param buf Determines if this invoke is buffered
	 */
	void draw(hwlib::window& w, hwlib::buffering buf = hwlib::buffering::unbuffered);
};