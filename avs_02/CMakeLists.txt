cmake_minimum_required(VERSION 3.17)
project(avs_02)

set(CMAKE_CXX_STANDARD 17)

add_executable(avs_02 main.cpp Vehicle.h Car.cpp Car.h Bus.cpp Bus.h Truck.cpp Truck.h Container.cpp Container.h)