#ifndef RGB_MATRIX_HPP
#define RGB_MATRIX_HPP

#include "rgb_matrix_port.hpp"
#include "rgb_matrix_part.hpp"
#include <hwlib-graphics.hpp>
#include <hwlib.hpp>

class rgb_matrix : public hwlib::window {
	private:
	rgb_matrix_port& port;
	rgb_matrix_part top;
	rgb_matrix_part bottom;
	
	virtual void write_implementation(hwlib::location l, hwlib::color c, hwlib::buffering buf) {};

	public:
	rgb_matrix(rgb_matrix_port& port) : hwlib::window(hwlib::location(32, 16), hwlib::black, hwlib::white), port(port), top(port.rgb0), bottom(port.rgb1) {}

	void write(hwlib::location pos, hwlib::color col, hwlib::buffering buf = hwlib::buffering::unbuffered);
	void write(hwlib::location pos, const hwlib::image& img, hwlib::buffering buf = hwlib::buffering::unbuffered);
	void write(hwlib::location pos, hwlib::buffering buf = hwlib::buffering::unbuffered);

	void show_frame();
	void loop();

	virtual void flush();
	virtual void clear(hwlib::buffering buf = hwlib::buffering::unbuffered);
};

#endif