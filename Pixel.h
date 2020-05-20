#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;

class Pixel{
    unsigned char red,green,blue;

public:
    Pixel(unsigned char red, unsigned char green, unsigned char blue);
    Pixel();
    float getRed(){
        return red;
    }
    float getGreen(){
        return green;
    }
    float getBlue(){
        return blue;
    }
    void setRed(int newR){
        red = newR;
    }
    void setGreen(int newG){
        green = newG;
    }
    void setBlue(int newB){
        blue = newB;
    }
    bool comparePixels(Pixel &a);
};
