//
//  student.hpp
//  burtgel
//
//  Created by MacUser on 11/9/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
class student{
private:
    int grade;
    int gpa;
public:
    char *name;
    char *id;
    student( );
    ~student( );
    student( char *nam, char *ida, int grad, int gp);
    void setName(char stn[]);
    void setId(char stn[]);
    void setGpa( int n);
    void setGrade( int n);
    char* getName();
    char* getId();
    int getGrade();
    int getGpa();
};

#endif /* student_hpp */


