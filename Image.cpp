#include <iostream>
#include <fstream>
#include "Image.h"

Image::Image(string fileName) {
    ifstream myfile(fileName,ios::in | ios::binary);
    try {
        myfile.seekg(12);
    }catch(...){
        throw runtime_error("not open!");
    }

    short w;
    short h;
    myfile.read((char*)&w,2);
    myfile.read((char*)&h,2);

    setHeight(h);
    setWidth(w);

    myfile.seekg(18);

    int totalP = h*w;

    for(int i=0;i<totalP;i++){
        int red;
        int green;
        int blue;
        myfile.read((char*)&blue,1);
        myfile.read((char*)&green,1);
        myfile.read((char*)&red,1);
        Pixel temp(red,green,blue);
        pixels.push_back(temp);
    }

    myfile.close();
}

Image::Image() {
    height = 0;
    width = 0;


}

Image::Image(const Image *obj){
    pixels = obj->pixels;
    height = obj->height;
    width = obj->width;
}

void Image::writeImage(string filename) {
    string inf = "../output/" + filename;
    ofstream myfile(inf,ios::out | ios::binary);
    unsigned char zero = 0;
    short zero2 = 0;
    unsigned char two = 2;
    unsigned char tf = 24;
    short widths = this->getWidth();
    short heights = this->getHeight();
    myfile.write((char*)&zero,1);
    myfile.write((char*)&zero,1);
    myfile.write((char*)&two,1);
    myfile.write((char*)&zero2,2);
    myfile.write((char*)&zero2,2);
    myfile.write((char*)&zero,1);
    myfile.write((char*)&zero2,2);
    myfile.write((char*)&zero2,2);
    myfile.write((char*)&widths,2);
    myfile.write((char*)&heights,2);
    myfile.write((char*)&tf,1);
    myfile.write((char*)&zero,1);

    int totP = this->getHeight()*this->getWidth();


    for(int i = 0;i<totP;i++){
        unsigned char b = this->pixels[i].getBlue();
        unsigned char g = this->pixels[i].getGreen();
        unsigned char r = this->pixels[i].getRed();

        myfile.write((char*)&b,1);
        myfile.write((char*)&g,1);
        myfile.write((char*)&r,1);
    }

    myfile.close();
}

void Image::isSameImage(Image &a){

    int size = a.pixels.size();
    for(int i=0;i<size;i++){
        if(!this->pixels[i].comparePixels(a.pixels[i])){
            cout << "Not the same image!! " <<"Different pixel @ " ;
            cout << i << endl;
            return;
        }
    }
    cout << "Is the same Image! + 11pts";
    cout << endl;

}

Image Image::multiply(Image &a){
    Image temp = Image();
    if(a.getHeight()*a.getHeight() == this->getHeight()*this->getWidth()){
        int totP = a.getWidth()*a.getHeight();
        temp.setHeight(a.getHeight());
        temp.setWidth(a.getWidth());

        for(int i=0;i<totP;i++){

            float tempRA = (a.pixels[i].getRed())/255.0;
            float tempGA = (a.pixels[i].getGreen())/255.0;
            float tempBA = (a.pixels[i].getBlue())/255.0;

            float tempRB = (this->pixels[i].getRed())/255.0;
            float tempGB = (this->pixels[i].getGreen())/255.0;
            float tempBB = (this->pixels[i].getBlue())/255.0;

            int cR = tempRA * tempRB * 255.0 + 0.5;
            int cG = tempGA * tempGB * 255.0 + 0.5;
            int cB = tempBA * tempBB *255.0 + 0.5;

            Pixel tempP = Pixel(cR,cG,cB);
            temp.pixels.push_back(tempP);
        }

    }
    return temp;
}

Image Image::subtract(Image &a) {
    Image temp = Image();
    if(a.getHeight()*a.getHeight() == this->getHeight()*this->getWidth()) {
        int totP = a.getWidth() * a.getHeight();
        temp.setHeight(a.getHeight());
        temp.setWidth(a.getWidth());

        for (int i = 0; i < totP; i++) {

            int tempRA = (a.pixels[i].getRed());
            int tempGA = (a.pixels[i].getGreen());
            int tempBA = (a.pixels[i].getBlue());

            int tempRB = (this->pixels[i].getRed());
            int tempGB = (this->pixels[i].getGreen());
            int tempBB = (this->pixels[i].getBlue());

            int cR = tempRA - tempRB;
            if(cR < 0){
                cR = 0;
            }
            int cG = tempGA - tempGB;
            if(cG < 0){
                cG = 0;
            }
            int cB = tempBA - tempBB;
            if(cB < 0){
                cB = 0;
            }
            Pixel tempP = Pixel(cR, cG, cB);
            temp.pixels.push_back(tempP);
        }

    }
    return temp;

}

Image Image::screen(Image &a) {
    Image temp = Image();
    if(a.getHeight()*a.getHeight() == this->getHeight()*this->getWidth()){
        int totP = a.getWidth()*a.getHeight();
        temp.setHeight(a.getHeight());
        temp.setWidth(a.getWidth());

        for(int i=0;i<totP;i++){

            float tempRA = (a.pixels[i].getRed())/255.0;
            float tempGA = (a.pixels[i].getGreen())/255.0;
            float tempBA = (a.pixels[i].getBlue())/255.0;

            float tempRB = (this->pixels[i].getRed())/255.0;
            float tempGB = (this->pixels[i].getGreen())/255.0;
            float tempBB = (this->pixels[i].getBlue())/255.0;

            int cR = (1.0 - (1.0-tempRA) * (1.0-tempRB)) * 255.0 + 0.5;
            int cG = (1.0 - (1.0-tempGA) * (1.0-tempGB)) * 255.0 + 0.5;
            int cB = (1.0 - (1.0-tempBA) * (1.0-tempBB)) * 255.0 + 0.5;

            Pixel tempP = Pixel(cR,cG,cB);
            temp.pixels.push_back(tempP);
        }

    }
    return temp;
}

Image Image::overlay(Image &a) {
    Image temp = Image();
    if(a.getHeight()*a.getHeight() == this->getHeight()*this->getWidth()) {
        int totP = a.getWidth() * a.getHeight();
        temp.setHeight(a.getHeight());
        temp.setWidth(a.getWidth());

        for (int i = 0; i < totP; i++) {

            float tempR = this->pixels[i].getRed();
            float tempG = this->pixels[i].getGreen();
            float tempB = this->pixels[i].getBlue();
            float grayness = (tempR+tempG+tempB)/765.0;
            if(grayness <= 0.5){
                float tempRA = (a.pixels[i].getRed())/255.0;
                float tempGA = (a.pixels[i].getGreen())/255.0;
                float tempBA = (a.pixels[i].getBlue())/255.0;

                float tempRB = (this->pixels[i].getRed())/255.0;
                float tempGB = (this->pixels[i].getGreen())/255.0;
                float tempBB = (this->pixels[i].getBlue())/255.0;

                int cR = 2 * tempRA * tempRB * 255.0 + 0.5;
                int cG = 2 * tempGA * tempGB * 255.0 + 0.5;
                int cB = 2 * tempBA * tempBB *255.0 + 0.5;

                if(cR>255){
                    cR = 255;
                }
                if(cG>255){
                    cG = 255;
                }
                if(cB>255){
                    cB = 255;
                }

                Pixel tempP = Pixel(cR,cG,cB);
                temp.pixels.push_back(tempP);
            }else{
                float tempRA = (a.pixels[i].getRed())/255.0;
                float tempGA = (a.pixels[i].getGreen())/255.0;
                float tempBA = (a.pixels[i].getBlue())/255.0;

                float tempRB = (this->pixels[i].getRed())/255.0;
                float tempGB = (this->pixels[i].getGreen())/255.0;
                float tempBB = (this->pixels[i].getBlue())/255.0;

                int cR = (1.0 - 2 * (1.0-tempRA) * (1.0-tempRB)) * 255.0 + 0.5;
                int cG = (1.0 - 2 * (1.0-tempGA) * (1.0-tempGB)) * 255.0 + 0.5;
                int cB = (1.0 - 2 * (1.0-tempBA) * (1.0-tempBB)) * 255.0 + 0.5;

                if(cR>255){
                    cR = 255;
                }else if(cR<0){
                    cR=0;
                }
                if(cG>255){
                    cG = 255;
                }else if(cG<0){
                    cG=0;
                }
                if(cB>255){
                    cB = 255;
                }else if(cB<0){
                    cB=0;
                }

                Pixel tempP = Pixel(cR,cG,cB);
                temp.pixels.push_back(tempP);
            }
        }
    }
    return temp;


}

Image Image::add200Green() {
    Image temp = Image(this);
    int totP = width*height;
    for(int i =0; i<totP;i++){

        int g = temp.pixels[i].getGreen() + 200;
        if(g>255){
            g = 255;
        }
        temp.pixels[i].setGreen(g);

    }
    return temp;

}

Image Image::scaleRed4scaleBlue0() {
    Image temp = Image(this);
    int totP = height*width;
    for(int i = 0; i<totP;i++){

        int r = temp.pixels[i].getRed()*4;
        if(r>255){
            r = 255;
        }
        temp.pixels[i].setRed(r);
        temp.pixels[i].setBlue(0);
    }
    return temp;
}

void Image::splitRGB(Image &r, Image &g, Image &b) {
    Image tempR = Image(this);
    Image tempG = Image(this);
    Image tempB = Image(this);

    int totP = height*width;

    for(int i = 0;i<totP;i++){
        tempR.pixels[i].setGreen(tempR.pixels[i].getRed());
        tempR.pixels[i].setBlue(tempR.pixels[i].getRed());
    }
    r = tempR;

    for(int i = 0;i<totP;i++){
        tempG.pixels[i].setRed(tempG.pixels[i].getGreen());
        tempG.pixels[i].setBlue(tempG.pixels[i].getGreen());
    }
    g = tempG;

    for(int i = 0;i<totP;i++){
        tempB.pixels[i].setGreen(tempB.pixels[i].getBlue());
        tempB.pixels[i].setRed(tempB.pixels[i].getBlue());
    }
    b = tempB;


}

Image Image::addGB(Image &g, Image &b) {
    Image &temp = *this;
    int totP = height*width;
    for(int i=0;i<totP;i++){
        temp.pixels[i].setGreen(g.pixels[i].getGreen());
        temp.pixels[i].setBlue(b.pixels[i].getBlue());
    }
    return temp;


}

Image Image::Image180() {
    Image temp = Image();
    int totP = height * width;
    temp.setWidth(width);
    temp.setHeight(height);

    for (int i = totP - 1; i > -1; i--) {
        temp.pixels.push_back(pixels[i]);
    }

    return temp;
}

Image Image::merge4(Image &pattern,Image &car,Image &circle){
    Image temp = Image();
    temp.setHeight(1024);
    temp.setWidth(1024);
    int textC = 0,patterC = 0,circlesC = 0,carC = 0;
    for(int i= 0;i<temp.height;i++){
       for(int j = 0;j<temp.width;j++){
           if(i<512 && j<512){
               temp.pixels.push_back(this->pixels[textC]);
               textC++;
           }
           else if(i<512 && j>=512){
               temp.pixels.push_back(pattern.pixels[patterC]);
               patterC++;
           }
           else if(j<512){
               temp.pixels.push_back(car.pixels[carC]);
               carC++;
           }
           else{
               temp.pixels.push_back(circle.pixels[circlesC]);
               circlesC++;
           }
       }
    }

    return temp;

}

