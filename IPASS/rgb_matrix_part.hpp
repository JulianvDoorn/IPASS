//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include "rgb_pins.hpp"
#include <hwlib.hpp>

/**
 * @class rgb_matrix_part
 * @author Julian
 * @date 20/06/17
 * @file rgb_matrix_part.hpp
 * @brief The matrix that rgb_matrix is written for exists out of two parts. This class can represent either the topper or lower half of the matrix. This depends on what rgb_pins you pass it.
 */
class rgb_matrix_part {
	private:
	rgb_pins& rgb;

	public:
	hwlib::color pixels[8][32];

	/**
	 * @brief Constructs half a matrix using the related rgb_pins port
	 * @param rgb rgb_pins to pass values with
	 */
	rgb_matrix_part(rgb_pins& rgb) : rgb(rgb) {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 32; x++) {
				pixels[y][x] = 0;
			}
		}
	}

	/**
	 * @brief Writes a pixel to the display buffer
	 * @param l X/Y location of the pixel
	 * @param c Color value of the pixel
	 */
	void write(const hwlib::location l, hwlib::color c) {
		pixels[l.y][l.x] = c;
	}

	/**
	 * @brief Passes the rgb_pins instance a 3 bit color value 
	 * @param c 3 bit color value
	 */
	void emit(uint_fast8_t c) {
		rgb.set(c);
	}
};