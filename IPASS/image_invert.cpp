#include "image_invert.hpp"

hwlib::color image_invert::get_implementation(hwlib::location pos) const {
	const hwlib::color c = slave[pos];
	const hwlib::color inverse_c = hwlib::color(0xFF - c.red, 0xFF - c.green, 0xFF - c.blue);
	return inverse_c;
}