//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include "text_label.hpp"
#include "updating_drawable.hpp"
#include <hwlib.hpp>

class updating_text_label : public updating_drawable, public text_label {
	public:
	updating_text_label(const char* text, hwlib::location pos, hwlib::font& f) : updating_drawable(pos), text_label(text, pos, f) {}
	
	void draw(hwlib::window& w, hwlib::buffering buf = hwlib::buffering::unbuffered) {
		text_label::draw(w, buf);
	}

	virtual void update() override {}
};