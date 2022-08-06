//
//  square.cpp
//  shape
//
//  Created by MacUser on 11/21/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#include "square.hpp"
#include "TwoDimen.hpp"
#include "shape.hpp"
#include<iostream>
using namespace std;
square::square(){};
square::square(int a, int b, int t):TwoDimen("square",x,y){
    setXY(a, b,t);
}


void square::setXY(int a, int b, int c){
    x = a;
    y = b;
    setT(c);
}

void square::setT(int t){
    tal = t;
    XRtop = x+tal;
    YRtop = y;
    XLbot = x;
    YLbot = y-tal;
    XRbot = XRtop-tal;
    YRbot = YLbot + tal;
}

int square::getT(){
    return tal;
}

float square::perimetr(){
    return 4*tal;
}

float square::findS(){
    return tal*tal;
}
