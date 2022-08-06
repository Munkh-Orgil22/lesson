//
//  toirog.cpp
//  sortshape
//
//  Created by MacUser on 12/13/18.
//  Copyright © 2018 MacUser. All rights reserved.
//
#include "TwoDimen.hpp"
#include "toirog.hpp"
#include "shape.hpp"
toirog::toirog():TwoDimen(){
    
}
toirog::toirog(int x, int y, int r):TwoDimen("toirog",x,y){
    setR(r);
}
void toirog::setR(int r){
    rad = r;
}
float toirog::findS(){
    return 3.14*rad;
}
float toirog::perimetr(){
    return 3.14*3.14*rad;
}
