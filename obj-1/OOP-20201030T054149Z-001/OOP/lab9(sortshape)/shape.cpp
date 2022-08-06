
//
//  shape.cpp
//  shape
//
//  Created by MacUser on 11/20/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#include "shape.hpp"
#include <string>
shape::shape(){
    setX(0);  //
    setY(0);
    color = "red";
}

shape::shape(string & color, int a, int b){
    setColor(color);
    setX(a);
    setY(b);
}

string shape::getColor(){
    return color;
}

void shape::setColor(string &col){
    color = col;
}

void shape::setX(int a){
    x = a;
}
void shape::setY(int b){
    y = b;
}

int shape::getX(){
    return x;
}

int shape::getY(){
    return y;
}
