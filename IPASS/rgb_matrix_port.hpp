#pragma once
#include <hwlib.hpp>
#include "rgb_pins.hpp"

/**
 * @class rgb_matrix_port
 * @author Julian
 * @date 20/06/17
 * @file rgb_matrix_port.hpp
 * @brief RGB matrix port class. Used for constructing a port of pin_outs to use inside rgb_matrix 
 */
class rgb_matrix_port {
	public:
	rgb_pins& rgb0;
	rgb_pins& rgb1;
	hwlib::port_out& address;
	hwlib::pin_out& clock;
	hwlib::pin_out& latch;
	hwlib::pin_out& output_enabled;

	/**
	 * @brief Constructs a 12 pin port using the given ports/pins
	 * @param rgb0 rgb_pins used for assigning RGB values to the upper half of the matrix
	 * @param rgb1 rgb_pins used for assigning RGB values to the lower half of the matrix
	 * @param address 3 pin port_out used for selecting a row
	 * @param clock pin_out used for determining the clock speed
	 * @param latch pin_out used for latching a row
	 * @param output_enabled pin_out used for enabling and disabling input to the matrix
	 */
	rgb_matrix_port(rgb_pins& rgb0, rgb_pins& rgb1, hwlib::port_out_from_pins& address, hwlib::target::pin_out& clock, hwlib::target::pin_out& latch, hwlib::target::pin_out& output_enabled) : rgb0(rgb0), rgb1(rgb1), address(address), clock(clock), latch(latch), output_enabled(output_enabled) {}
};