#pragma once
#include <hwlib.hpp>

class image_invert : public hwlib::image {
	private:
	const hwlib::image& slave;
	hwlib::color get_implementation(hwlib::location pos) const override {
		const hwlib::color c = slave[pos];
		const hwlib::color inverse_c = hwlib::color(0xFF - c.red, 0xFF - c.green, 0xFF - c.blue);
		return inverse_c;
	}

	public:
	/**
	 * @brief Constructs an inversion decorator for images
	 * @param slave Existing image to invert
	 */
	image_invert(const hwlib::image& slave) : hwlib::image(slave.size), slave(slave) {}
};