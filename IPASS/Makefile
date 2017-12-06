#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := rgb_matrix.cpp graphics_drawer.cpp image_invert.cpp image_rainbow.cpp rainbow_text_label.cpp text_label.cpp

# header files in this project
HEADERS := graphics_drawer.hpp image_invert.hpp image_rainbow.hpp rainbow.hpp rainbow_text_label.hpp
HEADERS += rgb_matrix.hpp rgb_matrix_part.hpp rgb_matrix_port.hpp rgb_pins.hpp text_label.hpp updating_text_slide.hpp text_slide.hpp
HEADERS += updating_drawable.hpp window_offset.hpp

# other places to look for files for this project
SEARCH  := 

# set RELATIVE to the next higher directory 
# and defer to the appropriate Makefile.* there
RELATIVE := ..
include $(RELATIVE)/Makefile.due
