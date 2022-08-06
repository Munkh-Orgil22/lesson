//
//  shape.hpp
//  shape
//
//  Created by MacUser on 11/20/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#ifndef shape_hpp
#define shape_hpp
#include<string>
#include <stdio.h>
using namespace std;


class shape{
private:
    string color;
protected:
    int x ; //olon coordinat class-d hadgalah
    int y ;
public:
    shape();
    shape(string &color, int a, int b);
    string getColor();
    void setX(int);   //array-d hussen elementendee utga onooh 2int avsan
    void setY(int);
    int getX();
    int getY();
    void setColor(string &color);
    virtual float perimetr() = 0;

    
};
#endif /* shape_hpp */
