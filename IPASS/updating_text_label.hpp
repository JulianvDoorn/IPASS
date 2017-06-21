#pragma once
#include "image_invert.hpp"
#include "image_rainbow.hpp"
#include "text_label.hpp"
#include "updating_drawable.hpp"
#include <hwlib.hpp>

class updating_text_label : public updating_drawable, public text_label {
	public:
	updating_text_label(const char* text, hwlib::location pos, const hwlib::font& f) : updating_drawable(pos), text_label(text, pos, f) {}
	
	void draw(hwlib::window& w, const hwlib::buffering buf = hwlib::buffering::unbuffered) {
		text_label::draw(w, buf);
	}

	virtual void update() override {}
};