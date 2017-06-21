#pragma once
#include "text_slide.hpp"
#include "updating_text_label.hpp"
#include "window_offset.hpp"
#include <hwlib.hpp>

class updating_text_slide : public text_slide, public updating_drawable {
	updating_text_label& slave;
	
	public:
	updating_text_slide(updating_text_label& slave) : text_slide(slave), updating_drawable(slave), slave(slave) {}

	void draw(hwlib::window& w, const hwlib::buffering buf = hwlib::buffering::unbuffered) {
		text_slide::draw(w, buf);
	}

	void update() override {
		slave.update();
	}
};