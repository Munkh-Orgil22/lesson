//
//  lesson.hpp
//  burtgel
//
//  Created by MacUser on 11/9/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#ifndef lesson_hpp
#define lesson_hpp
#include "student.hpp"
#include "teacher.hpp"
#include "lesson.hpp"
#include "burtgel.hpp"
#include <stdio.h>
#include <string>
using namespace std;
class lesson{
private:
    char *name;
    teacher bagsh;
public:
    student oyutan[50];
    burtgel regist[17];
    string sedev[17];
    
    lesson();
    ~lesson( );
    lesson( char *nam, teacher bag, student stn[], int n);
    
    void setName(char stn[]);
    char* getName();
    
    void setSedev(string stn, int x4);
    string getSedev(int x4);

};
#endif /* lesson_hpp */
