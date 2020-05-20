cmake_minimum_required(VERSION 3.12)
project(Project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ImageProcessing main.cpp Pixel.cpp Pixel.h Image.cpp Image.h)