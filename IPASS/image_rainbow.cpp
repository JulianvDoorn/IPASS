#include "image_rainbow.hpp"

hwlib::color image_rainbow::get_implementation(hwlib::location pos) const {
	if (slave[pos].rgb() != 0x000000) {
		return rainbow[(pos.x + pos.y + iteration_n) % 14];
	} else {
		return hwlib::black;
	}
}