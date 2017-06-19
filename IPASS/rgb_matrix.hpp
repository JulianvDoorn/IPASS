#pragma once
#include <hwlib.hpp>
#include "rgb_matrix_port.hpp"
#include "rgb_matrix_part.hpp"
#include "graphics_drawer.hpp"

class rgb_matrix : public graphics_drawer {
	private:
	rgb_matrix_port& port;
	rgb_matrix_part top;
	rgb_matrix_part bottom;
	
	virtual void write_implementation(hwlib::location l, hwlib::color c, hwlib::buffering buf);

	public:
	rgb_matrix(rgb_matrix_port& port) : graphics_drawer(hwlib::location(32, 16), hwlib::white, hwlib::black), port(port), top(port.rgb0), bottom(port.rgb1) {}

	void show_frame();
	void loop();

	virtual void flush();
	virtual void clear(hwlib::buffering buf = hwlib::buffering::unbuffered);
	
	rgb_matrix& operator<<(hwlib::drawable& drawing) {
		drawings[drawings_c] = &drawing;
		drawings_c++;
		return *this;
	}
};