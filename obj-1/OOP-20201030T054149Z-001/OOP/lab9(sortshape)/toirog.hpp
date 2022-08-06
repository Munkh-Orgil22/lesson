//
//  toirog.hpp
//  sortshape
//
//  Created by MacUser on 12/13/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#ifndef toirog_hpp
#define toirog_hpp
#include"TwoDimen.hpp"
#include "shape.hpp"
#include <iostream>
#include <stdio.h>
class toirog: public TwoDimen{
public:
    int rad;
    string name;
    toirog();
    toirog(int x, int y, int r);
    float findS();
    float perimetr();
    void setR(int r);
};


#endif /* toirog_hpp */
