//
//  burtgel.hpp
//  burtgel
//
//  Created by MacUser on 11/14/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#ifndef burtgel_hpp
#define burtgel_hpp
#include <stdio.h>
#include <iostream>
#include <string>
#include "teacher.hpp"
#include "student.hpp"
using namespace std;
class burtgel{
public:
    student oyutan[50];
    teacher bagsh;
    
    int burt[17];
    void irts(int k);
    int getIrts(int k);
    burtgel(){};
    ~burtgel(){};
    burtgel(student *a, int n, string b[], int k, teacher *b, lesson *c[]);
};





#endif /* burtgel_hpp */
