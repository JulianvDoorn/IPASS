#pragma once
#include "rainbow.hpp"
#include <hwlib.hpp>

class image_rainbow : public hwlib::image {
	private:
	const hwlib::image& slave;
	uint_fast8_t& iteration_n;

	hwlib::color get_implementation(hwlib::location pos) const override {
		if (slave[pos].rgb() != 0x000000) {
			return rainbow[(pos.x + pos.y + iteration_n) % 14];
		} else {
			return hwlib::black;
		}
	}

	public:
	/**
	 * @brief Constructor for a rainbow overlay decorator for images
	 * @details
	 * iteration_n is made a reference so it becomes more easy to synchronise multiple rainbow decorators
	 * @param slave Slave image to apply decorator to
	 * @param iteration_n Reference to uint_fast8_t to set the rainbow position
	 */
	image_rainbow(const hwlib::image& slave, uint_fast8_t& iteration_n) : hwlib::image(slave.size), slave(slave), iteration_n(iteration_n) {}
};