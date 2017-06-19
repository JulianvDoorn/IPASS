#pragma once
#include <hwlib.hpp>

class rgb_pins : public hwlib::port_out {
	private:
	hwlib::pin_out& r;
	hwlib::pin_out& g;
	hwlib::pin_out& b;

	public:
	uint_fast8_t number_of_pins() override {
		return 3;
	}

	void set(uint_fast8_t c, hwlib::buffering buf = hwlib::buffering::unbuffered) override {
		r.set(c & 0b100, buf);
		g.set(c & 0b010, buf);
		b.set(c & 0b001, buf);
	}

	rgb_pins(hwlib::target::pin_out& r, hwlib::target::pin_out& g,hwlib:: target::pin_out& b) : r(r), g(g), b(b){};
};