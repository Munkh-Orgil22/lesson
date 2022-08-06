//
//  student.cpp
//  student
//  Created by MacUser on 10/25/18.
//  Copyright © 2018 MacUser. All rights reserved.
//


#include "student.hpp"
#include <iostream>
#include<string>

using namespace std;
student::student(){
    name = new char[20];
    strcpy(name,"test");
    id = new char[16];
    strcpy(id,"18b1num0000");
    grade = 1;
    gpa = 0;
}
student::student(char *n, char *i, int gra, int g){
    name = new char[strlen(n)+1];
    strcpy(name, n);
    id = new char[strlen(i)+1];
    strcpy(name, i);
    grade=gra;
    gpa = g;
}
student::student(const student &stn){
    id = new char[strlen(stn.id)+1];
    id = stn.id;
}
student::~student(){
    delete []name;
    delete []id;
    cout<<"successfully deleted yeah bro :))"<<endl;
}
bool student::greatThan(student &stn){
    if(grade>stn.grade)
        return 1;
    return 0;
}
bool student::lessThan(student &stn){
    if(grade<stn.grade)
        return 1;
    else
        return 0;
}
bool student::isEqual(student &stn){
    if(grade==stn.grade)
        return 1;
    else
        return 0;
}
bool student::before(student &stn){
    if(strcmp(stn.name,name)<0)
        return 1;
    else
        return 0;
}
bool student::after(student &stn){
    if(strcmp(name, stn.name)>0)
        return 1;
    return 0;
}
void student::setName(char stn[]){
    delete []name;
    name = new char[strlen(stn)+1];
    strcpy(name, stn);
}
void student::setId(char stn[]){
    delete []id;
    id = new char[strlen(stn)+1];
    strcpy(id ,stn);
}
void student::setGrade(int n){
    if(n>0 && n<=4)
        grade = n;
    else
        cout<<"grade again: ";
}
void student::setGpa(int n){
    if(n>0 && n<=4)
        gpa = n;
    else
        cout<<"gpa again";
}
char* student::getName(){
    return name;
}
char* student::getId(){
    return id;
}
int student::getGrade(){
    return grade;
}
int student::getGpa(){
    return gpa;
}
