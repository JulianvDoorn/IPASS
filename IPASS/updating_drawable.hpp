#pragma once
#include <hwlib.hpp>

class updating_drawable : drawable {
	void draw(hwlib::window w) override;
	void update();
	void interact(hwlib::drawable other);
}