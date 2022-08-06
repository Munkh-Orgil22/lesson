//
//  Circle.hpp
//  shape
//
//  Created by MacUser on 11/21/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp
#include "TwoDimen.hpp"
#include"shape.hpp"
#include<iostream>
#include <stdio.h>
class circle: public TwoDimen{
public:
    int radius;
    string name;
    circle();
    circle(int x, int y, int r);
    void setR(int r);
    int getR();
    float findS();
    float perimetr();
    string getName();
    void setName();
    
    
};
#endif /* Circle_hpp */
