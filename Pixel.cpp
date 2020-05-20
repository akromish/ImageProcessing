#include "Pixel.h"
using namespace std;


Pixel::Pixel() {
    red = 0;
    green = 0;
    blue = 0;
}

Pixel::Pixel(unsigned char red, unsigned char green, unsigned char blue) {
    this->red = red;
    this->green=green;
    this->blue = blue;
}

bool Pixel::comparePixels(Pixel &a) {
    return red == a.getRed() && green == a.getGreen() && blue == a.getBlue();
}