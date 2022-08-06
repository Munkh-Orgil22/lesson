//
//  square.hpp
//  shape
//
//  Created by MacUser on 11/21/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#ifndef square_hpp
#define square_hpp
#include"shape.hpp"
#include"TwoDimen.hpp"
#include <stdio.h>
class square: public TwoDimen{
public:
    int tal, XRtop, YRtop, XLbot, YLbot, XRbot, YRbot;
    string name;
    square();
    square(int a, int b, int t);
    void setXY(int a, int b, int c);
    void setT(int t);
    int getT();
    float perimetr();
    float findS();
    
};
#endif /* square_hpp */
