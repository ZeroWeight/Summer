cmake_minimum_required(VERSION 2.8)
project( Star )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( Star new.cpp )
target_link_libraries( Star ${OpenCV_LIBS} )
