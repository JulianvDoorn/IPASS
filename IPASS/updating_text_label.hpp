//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include "text_label.hpp"
#include "updating_drawable.hpp"
#include <hwlib.hpp>

/**
 * @class updating_text_label
 * @author Julian
 * @date 22/06/17
 * @file updating_text_label.hpp
 * @brief text_label implementation with an update function
 */
class updating_text_label : public updating_drawable, public text_label {
public:
	/**
	 * @brief Constructs all superclasses with the provided arguments
	 * @param text Text to display
	 * @param pos Position to display at
	 * @param f Font to display with
	 */
	updating_text_label(const char* text, hwlib::location pos, hwlib::font& f) : updating_drawable(pos), text_label(text, pos, f) {}
	
	/**
	 * @copydoc text_label::draw
	 */
	void draw(hwlib::window& w, hwlib::buffering buf = hwlib::buffering::unbuffered) {
		text_label::draw(w, buf);
	}

	/**
	 * @copydoc updating_drawable::update
	 */
	virtual void update() override {}
};