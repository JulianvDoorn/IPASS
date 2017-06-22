//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "image_rainbow.hpp"

hwlib::color image_rainbow::get_implementation(hwlib::location pos) const {
	if (slave[pos].rgb() != 0x000000) {
		return rainbow[(pos.x + pos.y + color_offset) % 14];
	} else {
		return hwlib::black;
	}
}