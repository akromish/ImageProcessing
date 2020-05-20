#pragma once
#include <iostream>
#include <vector>
#include "Pixel.h"


class Image{
    int height;
    int width;

public:
    std::vector<Pixel> pixels;
    void setHeight(int h){
        height = h;
    }
    void setWidth(int w){
        width = w;
    }
    int getHeight(){
        return height;
    }
    int getWidth(){
        return width;
    }
    Image(std::string fileName);
    Image();
    Image(const Image *obj);
    void writeImage(std::string filename);
    void isSameImage(Image &a);
    Image multiply(Image &a);
    Image subtract(Image &a);
    Image screen(Image &a);
    Image overlay(Image &a);
    Image add200Green();
    Image scaleRed4scaleBlue0();
    void splitRGB(Image& r,Image& g,Image& b);
    Image addGB(Image &g,Image &b);
    Image Image180();
    Image merge4(Image &pattern,Image &car,Image &circle);
};