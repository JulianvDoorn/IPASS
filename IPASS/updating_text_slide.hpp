//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include "text_slide.hpp"
#include "updating_drawable.hpp"
#include "updating_text_label.hpp"
#include <hwlib.hpp>

/**
 * @class updating_text_slide
 * @author Julian
 * @date 20/06/17
 * @file updating_text_slide.hpp
 * @brief This class applies a slide effect to updating_text_labels
 */
class updating_text_slide : public text_slide, public updating_drawable {
	private:
	updating_text_label& slave;

public:
	/**
	 * @brief Constructs all superclasses and slave
	 * @param slave updating_text_label to apply effect to
	 */
	updating_text_slide(updating_text_label& slave) : text_slide(slave), updating_drawable(slave), slave(slave) {}

	/**
	 * @copydoc text_slide::draw
	 */
	void draw(hwlib::window& w, hwlib::buffering buf = hwlib::buffering::unbuffered) {
		text_slide::draw(w, buf);
	}

	/**
	 * @copydoc updating_drawable::update
	 */
	void update() override {
		slave.update();
	}
};