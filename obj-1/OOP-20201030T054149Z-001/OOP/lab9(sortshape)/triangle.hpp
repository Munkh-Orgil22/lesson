//
//  triangle.hpp
//  shape
//
//  Created by MacUser on 11/27/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#ifndef triangle_hpp
#define triangle_hpp
#include "TwoDimen.hpp"
#include"shape.hpp"
#include<iostream>
#include <stdio.h>
using namespace std;
class triangle: public TwoDimen{
public:
    int tal;
    string name;
    triangle();
    triangle(int x, int y, int t);
    void setT(int t);
    int getT();
    float perimetr();
    float findS();
};



#endif /* triangle_hpp */
