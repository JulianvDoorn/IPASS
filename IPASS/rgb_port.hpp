#ifndef RGB_PORT_HPP
#define RGB_PORT_HPP

#include <hwlib-port.hpp>

using namespace hwlib;

class rgb_port : public port_out {
	private:
	pin_out& r;
	pin_out& g;
	pin_out& b;

	public:
	uint_fast8_t number_of_pins() override {
		return 3;
	}

	void set(uint_fast8_t c, buffering buf = buffering::unbuffered) override {
		r.set(c & 0b100, buf);
		g.set(c & 0b010, buf);
		b.set(c & 0b001, buf);
	}

	rgb_port(target::pin_out& r, target::pin_out& g, target::pin_out& b) : r(r), g(g), b(b){};
};

#endif // RGB_PORT_HPP
