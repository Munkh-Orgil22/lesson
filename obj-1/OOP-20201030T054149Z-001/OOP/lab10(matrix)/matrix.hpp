//
//  matrix.hpp
//  matrix
//
//  Created by MacUser on 12/5/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
#endif /* matrix_hpp */
class matrix
{
private:
    int r,c;
    float **mat;
public:
    matrix();
    matrix(int row, int col);
    int getRows();
    int getCols();
    void initmatrix();
    void setMat();
    int getValue(int i, int j);
    void show();
    matrix operator +(matrix a);
    matrix operator =(matrix a);
    matrix operator -(matrix a);
    matrix operator *(matrix a);
    void operator +(float a);
    void operator ++(void);
    void operator --(void);
    void operator +=(matrix a);
    void operator -=(matrix a);
    void operator *=(matrix a);
    void operator !(void);
};
