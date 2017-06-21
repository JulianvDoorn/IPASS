#pragma once
#include "rgb_pins.hpp"
#include <hwlib.hpp>

class rgb_matrix_part {
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
	void emit(const uint_fast8_t c) {
		rgb.set(c);
	}
};