//          Copyright Julian van Doorn 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "graphics_drawer.hpp"

void graphics_drawer::draw_all() {
	for (uint_fast8_t i = 0; i < drawings_c; i++) {
		drawings[i]->draw(*this);
	}

	for (uint_fast8_t i = 0; i < updating_drawings_c; i++) {
		updating_drawings[i]->draw(*this);
	}
}

void graphics_drawer::update_all() {
	for (uint_fast8_t i = 0; i < updating_drawings_c; i++) {
		updating_drawings[i]->update();
	}
}

graphics_drawer& graphics_drawer::operator<<(hwlib::drawable& drawing) {
	drawings[drawings_c] = &drawing;
	drawings_c++;
	return *this;
}

graphics_drawer& graphics_drawer::operator<<(updating_drawable& drawing) {
	updating_drawings[updating_drawings_c] = &drawing;
	updating_drawings_c++;
	return *this;
}