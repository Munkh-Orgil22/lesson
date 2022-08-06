//
//  student.cpp
//  burtgel
//
//  Created by MacUser on 11/9/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#include "student.hpp"
#include<iostream>
student::student(){
    name = new char[20];
    strcpy(name, " ");
    
    id = new char[20];
    strcpy(id, " ");
    
    grade = 1;
    
    gpa = 0;
}

student::~student(){
    delete[] name;
    delete[] id;
}

student::student(char *nam, char *ida, int grad, int gp){
    delete[] name;
    name = new char[strlen(nam)+1];
    strcpy(name, nam);
    
    delete[] ida;
    id = new char[strlen(ida)+1];
    strcpy(id, ida);
    
    grade = grad;
    
    gpa = gp;
}

void student::setName(char stn[]){
    delete[] name;
    name = new char[strlen(stn)+1];
    strcpy(name, stn);
}

void student::setId(char stn[]){
    delete[] id;
    id = new char[strlen(stn)+1];
    strcpy(id, stn);
}

void student::setGpa(int n){
    gpa = n;
}

void student::setGrade(int n){
    grade = n;
}

char* student::getName(){
    return name;
}

char* student::getId(){
    return id;
}

int student::getGpa(){
    return gpa;
}

int student::getGrade(){
    return grade;
}
