#include <iostream>
#include "Image.h"

int main() {

    // storing all the input/example images
    Image car = Image("../input/car.tga");
    Image circles = Image("../input/circles.tga");
    Image layer_blue = Image("../input/layer_blue.tga");
    Image layer_green = Image("../input/layer_green.tga");
    Image layer_red = Image("../input/layer_red.tga");
    Image layer1 = Image("../input/layer1.tga");
    Image layer2 = Image("../input/layer2.tga");
    Image pattern1 = Image("../input/pattern1.tga");
    Image pattern2 = Image("../input/pattern2.tga");
    Image text = Image("../input/text.tga");
    Image text2 = Image("../input/text2.tga");
    Image epart1 = Image("../examples/EXAMPLE_part1.tga");
    Image epart2 = Image("../examples/EXAMPLE_part2.tga");
    Image epart3 = Image("../examples/EXAMPLE_part3.tga");
    Image epart4 = Image("../examples/EXAMPLE_part4.tga");
    Image epart5 = Image("../examples/EXAMPLE_part5.tga");
    Image epart6 = Image("../examples/EXAMPLE_part6.tga");
    Image epart7 = Image("../examples/EXAMPLE_part7.tga");
    Image epart8b = Image("../examples/EXAMPLE_part8_b.tga");
    Image epart8g = Image("../examples/EXAMPLE_part8_g.tga");
    Image epart8r = Image("../examples/EXAMPLE_part8_r.tga");
    Image epart9 = Image("../examples/EXAMPLE_part9.tga");
    Image epart10 = Image("../examples/EXAMPLE_part10.tga");
    Image e_ec = Image("../examples/EXAMPLE_extraCredit.tga");

   std::cout<< "Make a selection of Task: 1-10 or hit 11 for EC task or hit 12 to test all  " << std::endl;
   int userIn;
   std::cin >> userIn;

   if(userIn == 1){
       // Part 1:

       std::cout<< "Testing Task 1:" << std::endl;

       Image c = layer1.multiply(pattern1);
       c.writeImage("part1.tga");

       std::cout<< "Is this the same image as the example?" << std::endl;
       c.isSameImage(epart1);

       std::cout<< std::endl;

   }else if(userIn == 2){

       // Part 2:
       std::cout<< "Testing Task 2:" << std::endl;
       Image g = layer2.subtract(car);
       g.writeImage("part2.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;

       g.isSameImage(epart2);
       std::cout<<std::endl;

   }else if(userIn == 3){

       // Part 3:
       std::cout<< "Testing Task 3:" <<std::endl;
       Image k = layer1.multiply(pattern2);

       Image m = text.screen(k);
       m.writeImage("part3.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;
       epart3.isSameImage(m);
       std::cout<<std::endl;


   }else if(userIn == 4){

       // Part 4:
       std::cout<< "Testing Task 4:" <<std::endl;
       Image o = layer2.multiply(circles);
       Image p = pattern2.subtract(o);
       p.writeImage("part4.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;
       p.isSameImage(epart4);
       std::cout<<std::endl;

   }else if(userIn == 5){

       // Part 5:
       std::cout<< "Testing Task 5:" <<std::endl;
       Image q = pattern1.overlay(layer1);
       q.writeImage("part5.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;

       q.isSameImage(epart5);
       std::cout<<std::endl;

   }else if(userIn == 6){

       // Part 6:
       std::cout<< "Testing Task 6:" <<std::endl;
       Image r = car.add200Green();
       r.writeImage("part6.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;

       r.isSameImage(epart6);
       std::cout<<std::endl;

   }else if(userIn == 7){

       // Part 7:
       std::cout<< "Testing Task 7:" <<std::endl;
       Image s = car.scaleRed4scaleBlue0();
       s.writeImage("part7.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;

       s.isSameImage(epart7);
       std::cout<<std::endl;

   }else if(userIn == 8){

       // Part 8
       Image t,u,v;
       car.splitRGB(t,u,v);

       t.writeImage("part8_r.tga");
       u.writeImage("part8_g.tga");
       v.writeImage("part8_b.tga");
       std::cout<< "Testing Task 8r:" <<std::endl;
       std::cout<< "Is this the same image as the example?" <<std::endl;
       t.isSameImage(epart8r);
       std::cout<<std::endl;

       std::cout<< "Testing Task 8g:" <<std::endl;
       std::cout<< "Is this the same image as the example?" <<std::endl;
       u.isSameImage(epart8g);
       std::cout<<std::endl;

       std::cout<< "Testing Task 8b:" <<std::endl;
       std::cout<< "Is this the same image as the example?" <<std::endl;
       v.isSameImage(epart8b);
       std::cout<<std::endl;

   }else if(userIn == 9){

       // Part 9:
       std::cout<< "Testing Task 9:" <<std::endl;
       Image w = layer_red.addGB(layer_green,layer_blue);
       w.writeImage("part9.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;

       w.isSameImage(epart9);
       std::cout<<std::endl;

   }else if(userIn == 10){

       // Part 10:
       std::cout<< "Testing Task 10:" <<std::endl;
       Image x = text2.Image180();
       x.writeImage("part10.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;

       x.isSameImage(epart10);
       std::cout<<std::endl;

   }else if(userIn == 11){

       // Part EC:
       std::cout<< "Testing EC Task:" <<std::endl;

       Image y = text.merge4(pattern1,car,circles);
       y.writeImage("ecPart.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;
       y.isSameImage(e_ec);

   }else if(userIn == 12){

       // Part 1:
       std::cout<< "Testing Task 1:" <<std::endl;

       Image c = layer1.multiply(pattern1);
       c.writeImage("part1.tga");

       std::cout<< "Is this the same image as the example?" <<std::endl;
       c.isSameImage(epart1);

       std::cout<<std::endl;


       // Part 2:
       std::cout<< "Testing Task 2:" <<std::endl;
       Image g = layer2.subtract(car);
       g.writeImage("part2.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;

       g.isSameImage(epart2);
       std::cout<<std::endl;


       // Part 3:
       std::cout<< "Testing Task 3:" <<std::endl;
       Image k = layer1.multiply(pattern2);

       Image m = text.screen(k);
       m.writeImage("part3.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;
       epart3.isSameImage(m);
       std::cout<<std::endl;


       // Part 4:
       std::cout<< "Testing Task 4:" <<std::endl;
       Image o = layer2.multiply(circles);
       Image p = pattern2.subtract(o);
       p.writeImage("part4.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;
       p.isSameImage(epart4);
       std::cout<<std::endl;


       // Part 5:
       std::cout<< "Testing Task 5:" <<std::endl;
       Image q = pattern1.overlay(layer1);
       q.writeImage("part5.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;

       q.isSameImage(epart5);
       std::cout<<std::endl;


       // Part 6:
       std::cout<< "Testing Task 6:" <<std::endl;
       Image r = car.add200Green();
       r.writeImage("part6.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;

       r.isSameImage(epart6);
       std::cout<<std::endl;


       // Part 7:
       std::cout<< "Testing Task 7:" <<std::endl;
       Image s = car.scaleRed4scaleBlue0();
       s.writeImage("part7.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;

       s.isSameImage(epart7);
       std::cout<<std::endl;


       // Part 8
       Image t,u,v;
       car.splitRGB(t,u,v);

       t.writeImage("part8_r.tga");
       u.writeImage("part8_g.tga");
       v.writeImage("part8_b.tga");
       std::cout<< "Testing Task 8r:" <<std::endl;
       std::cout<< "Is this the same image as the example?" <<std::endl;
       t.isSameImage(epart8r);
       std::cout<<std::endl;

       std::cout<< "Testing Task 8g:" <<std::endl;
       std::cout<< "Is this the same image as the example?" <<std::endl;
       u.isSameImage(epart8g);
       std::cout<<std::endl;

       std::cout<< "Testing Task 8b:" <<std::endl;
       std::cout<< "Is this the same image as the example?" <<std::endl;
       v.isSameImage(epart8b);
       std::cout<<std::endl;


       // Part 9:
       std::cout<< "Testing Task 9:" <<std::endl;
       Image w = layer_red.addGB(layer_green,layer_blue);
       w.writeImage("part9.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;

       w.isSameImage(epart9);
       std::cout<<std::endl;


       // Part 10:
       std::cout<< "Testing Task 10:" <<std::endl;
       Image x = text2.Image180();
       x.writeImage("part10.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;

       x.isSameImage(epart10);
       std::cout<<std::endl;


       // Part EC:12
       std::cout<< "Testing EC Task:" <<std::endl;

       Image y = text.merge4(pattern1,car,circles);
       y.writeImage("ecpart.tga");
       std::cout<< "Is this the same image as the example?" <<std::endl;
       y.isSameImage(e_ec);

   }
    return 0;
}











