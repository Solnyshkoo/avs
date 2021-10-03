cmake_minimum_required(VERSION 3.17)
project(avs_cpp_01)

set(CMAKE_CXX_STANDARD 14)

# Source files list
set(SOURCE_FILES
# Headers
vehicle.h
car.h
bus.h
truck.h
        container.h

# Sources
vehicle.cpp
car.cpp
bus.cpp
truck.cpp
        container.cpp
        main.cpp
)

add_executable(avs_cpp_01 ${SOURCE_FILES})