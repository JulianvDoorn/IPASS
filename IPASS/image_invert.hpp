//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include <hwlib.hpp>

/**
 * @class image_invert
 * @author Julian
 * @date 20/06/17
 * @file image_invert.hpp
 * @brief Inverts colors of an image
 */
class image_invert : public hwlib::image {
	private:
	const hwlib::image& slave;

	hwlib::color get_implementation(hwlib::location pos) const override {
		const hwlib::color c = slave[pos];
		const hwlib::color inverse_c = hwlib::color(0xFF - c.red, 0xFF - c.green, 0xFF - c.blue);
		return inverse_c;
	}

	public:
	/**
	 * @brief Constructs an inversion decorator for images
	 * @param slave Existing image to invert
	 */
	image_invert(const hwlib::image& slave) : hwlib::image(slave), slave(slave) {}
};