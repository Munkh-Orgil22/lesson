//
//  triangle.cpp
//  shape
//
//  Created by MacUser on 11/27/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#include "triangle.hpp"
#include<math.h>
triangle::triangle(){};
triangle::triangle(int x, int y, int t):TwoDimen("gurwaljin",x,y){
    setT(t);
}

void triangle::setT(int t){
    tal = t;
}

int triangle::getT(){
    return tal;
}

float triangle::findS(){
    float p = (float)(tal+tal+tal)/2;
    return sqrt(p*((p-tal)*3));
}

float triangle::perimetr(){
    float p = (float)(tal+tal+tal)/2;
    return p;
}
