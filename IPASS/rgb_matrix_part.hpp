#ifndef RGB_MATRIX_PART_HPP
#define RGB_MATRIX_PART_HPP

#include "rgb_pins.hpp"

class rgb_matrix_part {
	public:
	hwlib::color pixels[8][32];

	rgb_pins& rgb;

	rgb_matrix_part(rgb_pins& rgb) : rgb(rgb) {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 32; x++) {
				pixels[y][x] = 0;
			}
		}
	}

	void write(const hwlib::location l, hwlib::color c) {
		pixels[l.y][l.x] = c;
	}
	
	void emit(uint_fast8_t v) {
//		hwlib::cout << "emitting: " << v << hwlib::endl;
		rgb.set(v);
//		hwlib::cout << "returned" << hwlib::endl;
	}
};

#endif