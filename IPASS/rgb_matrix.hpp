#pragma once
#include <hwlib.hpp>
#include "rgb_matrix_port.hpp"
#include "rgb_matrix_part.hpp"
#include "graphics_drawer.hpp"

class rgb_matrix : public graphics_drawer {
	rgb_matrix_port& port;
	rgb_matrix_part top;
	rgb_matrix_part bottom;
	
	virtual void write_implementation(hwlib::location l, hwlib::color c, hwlib::buffering buf);

public:
	/**
	 * @brief Constructs a hwlib::window subclass dedicated to drawing multi-color values to an RGB matrix panel
	 * Link to the panel, since there is little product specfication an not even a useful s/n: https://www.adafruit.com/product/420
	 * @param port rgb_matrix_port with the pin definitions
	 */
	rgb_matrix(rgb_matrix_port& port, hwlib::color fg = hwlib::white, hwlib::color bg = hwlib::black) : graphics_drawer(hwlib::location(32, 16), fg, bg), port(port), top(port.rgb0), bottom(port.rgb1) {}

	/**
	 * @brief Displays a 4 cycle PWM (25% duty-cycle precision) display onto the matrix
	 */
	void show_frame();
	
	/**
	 * @brief Blocking function that keeps calling show_frame
	 */
	void loop();

	/**
	 * @brief Unimplemented in this window since if there was buffering the PWM wouldn't work correctly
	 */
	virtual void flush() {};
	
	/**
	 * @brief Resets all the pixels to the background color specified inside the constructor
	 * @param buf Doesn't affect anything
	 */
	virtual void clear(const hwlib::buffering buf = hwlib::buffering::unbuffered);
};