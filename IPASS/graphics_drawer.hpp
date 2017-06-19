#pragma once
#include <hwlib.hpp>

/*
class drawable {
public:

   /// the location where the object is drawn
   location start;

   /// create a drawable object by bsupplying its (initial) location
   drawable( location start ): start{ start }{}

   /// \brief
   /// interface to draw the object buffered
   /// \details
   /// You must supply the window.
   ///
   /// If buffering is specified, the actuial drawing can be delayed
   /// until flush() is aclled.
   virtual void draw( 
      window & w, 
      buffering buf = buffering::unbuffered 
   ) = 0;    

};
 */

class graphics_drawer : public hwlib::window {
	protected:
	uint_fast16_t drawings_c = 0;
	hwlib::drawable* drawings[256];

	public:
	graphics_drawer(hwlib::location size, hwlib::color foreground, hwlib::color background) : hwlib::window(size, foreground, background) {}
	
	void draw_all() {
		for (hwlib::drawable* drawing : drawings) {
			drawing->draw(*this);
		}
	}

	graphics_drawer& operator<<(hwlib::drawable& drawing) {
		drawings[drawings_c] = &drawing;
		drawings_c++;
		return *this;
	}
};