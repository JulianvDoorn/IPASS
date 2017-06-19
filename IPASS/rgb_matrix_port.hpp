#pragma once
#include <hwlib.hpp>
#include "rgb_pins.hpp"

class rgb_matrix_port {
	public:
	rgb_pins& rgb0;
	rgb_pins& rgb1;
	hwlib::port_out& address;
	hwlib::pin_out& clock;
	hwlib::pin_out& latch;
	hwlib::pin_out& output_enabled;

	rgb_matrix_port(rgb_pins& rgb0, rgb_pins& rgb1, hwlib::port_out_from_pins& address, hwlib::target::pin_out& clock, hwlib::target::pin_out& latch, hwlib::target::pin_out& output_enabled) : rgb0(rgb0), rgb1(rgb1), address(address), clock(clock), latch(latch), output_enabled(output_enabled) {}
};