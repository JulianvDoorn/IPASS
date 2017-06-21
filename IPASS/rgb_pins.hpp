#pragma once
#include <hwlib.hpp>

/**
 * @class rgb_pins
 * @author Julian
 * @date 19/06/17
 * @file rgb_pins.hpp
 * @brief RGB pins class. Used for selecting 3 pins for outputting 3 bit values.
 * This class is optimized for having a 3 pins port_out.
 */
class rgb_pins : public hwlib::port_out {
	private:
	hwlib::pin_out& r;
	hwlib::pin_out& g;
	hwlib::pin_out& b;

public:
	/**
	 * @copydoc hwlib::port_out::number_of_pins()
	 */
	uint_fast8_t number_of_pins() override {
		return 3;
	}

	/**
	 * @brief Accepts a 3 bit RGB value and sets them to the 3 rgb pins
	 * @param c 3 bit RGB value
	 * @param buf When buf == buffering::buffered, the pins are set once rgb_pins::flush() is called
	 */
	void set(uint_fast8_t c, hwlib::buffering buf = hwlib::buffering::unbuffered) override {
		r.set(c & 0b100, buf);
		g.set(c & 0b010, buf);
		b.set(c & 0b001, buf);
	}
	
	/**
	 * @copydoc hwlib::port_out::flush()
	 */
	void flush() {
		r.flush();
		g.flush();
		b.flush();
	}

	/**
	 * @brief Constructs an rgb_pins object.
	 * @param r pin_out for red values
	 * @param g pin_out for green values
	 * @param b pin_out for blue values
	 */
	rgb_pins(hwlib::target::pin_out& r, hwlib::target::pin_out& g,hwlib:: target::pin_out& b) : r(r), g(g), b(b){};
};