//
//  student.hpp
//  student
//
//  Created by MacUser on 10/25/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#ifndef student_hpp
#define student_hpp
#include<string>
#include <stdio.h>
#include<iostream>
using namespace std;
class student{
private:
    char *id;
    int gpa;
    static int members; //static gishuun ugugdul Class dotor zarlah
public:
    char *name;
    int grade;
    student();
    student(char* n, char* id, int gpa, int grade);
    student(const student &stn);
    ~student();
    bool greatThan(student &stn);
    bool lessThan(student &stn);
    bool isEqual(student &stn);
    bool before(student &stn);
    bool after(student &stn);
    void setName(char stn[]);
    void setId(char stn[]);
    void setGrade(int n);
    void setGpa(int n);
    char* getName();
    char* getId();
    int getGrade();
    int getGpa();

};

#endif /* student_hpp */
