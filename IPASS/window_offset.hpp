//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include <hwlib.hpp>

/**
 * @class window_offset
 * @author Julian
 * @date 22/06/17
 * @file window_offset.hpp
 * @brief Offsets all write calls with a given value
 */
class window_offset : public hwlib::window {
	private:
	hwlib::window& slave;
	hwlib::location offset;

	void write_implementation(const hwlib::location pos, const hwlib::color col, hwlib::buffering buf = hwlib::buffering::unbuffered) {
		slave.write(pos + offset, col, buf);
	}

public:
	/**
	 * @brief Constructs a window_offset decorator
	 * @param slave hwlib::window to apply effect to
	 * @param offset Value to use the for offsets
	 */
	window_offset(hwlib::window& slave, hwlib::location offset) : hwlib::window(slave), slave(slave), offset(offset) {}
};