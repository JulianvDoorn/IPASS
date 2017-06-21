#pragma once
#include <hwlib.hpp>
#include "updating_drawable.hpp"

class graphics_drawer : public hwlib::window {
	protected:
	uint_fast16_t drawings_c = 0;
	hwlib::drawable* drawings[128];
	
	uint_fast16_t updating_drawings_c = 0;
	updating_drawable* updating_drawings[128];

	public:
	/**
	 * @brief Constructs a hwlib::window with the ability to store drawables to draw continuously 
	 * @param size Size of the window
	 * @param foreground Default foreground color of the window
	 * @param background Background color of the window
	 */
	graphics_drawer(hwlib::location size, hwlib::color foreground, hwlib::color background) : hwlib::window(size, foreground, background) {}

	/**
	 * @brief Iterators over all stored drawables and draws them to 'this'
	 */
	void draw_all() {
		for (uint_fast8_t i = 0; i < drawings_c; i++) {
			drawings[i]->draw(*this);
		}
		
		for (uint_fast8_t i = 0; i < updating_drawings_c; i++) {
			updating_drawings[i]->draw(*this);
		}
	}
	
	void update_all() {
		for (uint_fast8_t i = 0; i < updating_drawings_c; i++) {
			updating_drawings[i]->update();
		}
	}

	/**
	 * @brief Implements the << operator for drawing a hwlib::drawable
	 * @param drawing Drawable to draw
	 * @return Reference to 'this' to chain <<'s
	 */
	graphics_drawer& operator<<(hwlib::drawable& drawing) {
		drawings[drawings_c] = &drawing;
		drawings_c++;
		return *this;
	}
	
	/**
	 * @brief Implements the << operator for drawing an updating_drawable
	 * @param drawing Drawable to draw
	 * @return Reference to 'this' to chain <<'s
	 */
	graphics_drawer& operator<<(updating_drawable& drawing) {
		updating_drawings[updating_drawings_c] = &drawing;
		updating_drawings_c++;
		return *this;
	}
};