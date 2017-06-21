#pragma once
#include <hwlib.hpp>

class window_offset : public hwlib::window {
	hwlib::window& slave;
	hwlib::location offset;

	void write_implementation(const hwlib::location pos, const hwlib::color col, const hwlib::buffering buf = hwlib::buffering::unbuffered) {
		slave.write(pos + offset, col, buf);
	}

	public:
	window_offset(hwlib::window& slave, hwlib::location offset) : hwlib::window(slave), slave(slave), offset(offset) {}
};