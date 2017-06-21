//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include "rainbow.hpp"
#include <hwlib.hpp>

/**
 * @class image_rainbow
 * @author Julian
 * @date 20/06/17
 * @file image_rainbow.hpp
 * @brief Class that applies a rainbow effect on top of all enabled pixels of an image
 */
class image_rainbow : public hwlib::image {
	private:
	const hwlib::image& slave;
	uint_fast8_t& iteration_n;

	hwlib::color get_implementation(hwlib::location pos) const override;

	public:
	/**
	 * @brief Constructor for a rainbow overlay decorator for images
	 * @details
	 * iteration_n is made a reference so it becomes more easy to synchronise multiple rainbow decorators
	 * @param slave Slave image to apply decorator to
	 * @param iteration_n Reference to uint_fast8_t to set the rainbow position
	 */
	image_rainbow(const hwlib::image& slave, uint_fast8_t& iteration_n) : hwlib::image(slave), slave(slave), iteration_n(iteration_n) {}
};