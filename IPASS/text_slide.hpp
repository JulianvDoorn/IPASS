//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include "text_label.hpp"
#include "window_offset.hpp"
#include <hwlib.hpp>

class text_slide : public text_label {
	private:
	text_label& slave;

	virtual void draw_implementation(hwlib::window& w, const hwlib::image& letter, const hwlib::location l_pos, hwlib::buffering buf) {
		const image_invert img = image_invert(letter);
		window_offset w_offset = window_offset(w, offset);

		slave.draw(w_offset);
	}

	public:
	hwlib::location offset = hwlib::location(0, 0);

	text_slide(updating_text_label& slave) : text_label(slave), slave(slave) {}

	void draw(hwlib::window& w, hwlib::buffering buf = hwlib::buffering::unbuffered) {
		text_label::draw(w, buf);
	}
};