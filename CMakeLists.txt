cmake_minimum_required(VERSION 2.8)
project(2017Vision)

find_package(OpenCV REQUIRED )

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(2017Vision ${SOURCE_FILES})

target_link_libraries( 2017Vision ${OpenCV_LIBS} )
