#pragma once
#include <hwlib.hpp>

class updating_drawable : public hwlib::drawable {
	public:
	updating_drawable(hwlib::location start) : hwlib::drawable(start){};

	/**
	 * @brief updating_drawable::draw is called every time the window classes requires the image to be drawn
	 * @param w hwlib::window to draw to
	 */
	virtual void draw(hwlib::window& w, const hwlib::buffering buf = hwlib::buffering::unbuffered) = 0;

	/**
	 * @brief updating_drawable::update is called every frame
	 */
	virtual void update(){};
};