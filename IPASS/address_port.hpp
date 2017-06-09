#ifndef ADDRESS_PORT_HPP
#define ADDRESS_PORT_HPP

#include <hwlib-port.hpp>

using namespace hwlib;

class address_port : port_out_from_pins {
	public:
	using port_out_from_pins::port_out_from_pins;
	using port_out_from_pins::set;
};

#endif // ADDRESS_PORT_HPP
