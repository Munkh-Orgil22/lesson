
//
//  TwoDimen.hpp
//  shape
//
//  Created by MacUser on 11/20/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#ifndef TwoDimen_hpp
#define TwoDimen_hpp

#include <stdio.h>
#include"shape.hpp"
class TwoDimen:public shape{
public:
    TwoDimen();
    TwoDimen(string col, int a, int b);
    virtual float findS() = 0;
    
};
#endif /* TwoDimen_hpp */
