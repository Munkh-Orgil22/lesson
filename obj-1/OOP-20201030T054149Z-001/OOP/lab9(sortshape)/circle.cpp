//
//  Circle.cpp
//  shape
//
//  Created by MacUser on 11/21/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#include "circle.hpp"
#include "shape.hpp"
#include"TwoDimen.hpp"
circle::circle():TwoDimen(){
    
}

circle::circle(int x, int y, int r) : TwoDimen("toirog1",x,y){
    setR(r);
}

void circle::setR(int r){
    radius = r;
}

int circle::getR(){
    return radius;
}
void circle::setName(){
    name = "toirog";
}
string circle::getName(){
    return name;
}

float circle::perimetr(){
    return radius*3.14*2;
}

float circle::findS(){
    return 2*3.14*radius;
}
