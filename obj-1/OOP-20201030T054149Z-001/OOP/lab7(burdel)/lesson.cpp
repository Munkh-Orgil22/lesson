//
//  lesson.cpp
//  burtgel
//
//  Created by MacUser on 11/9/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#include <stdio.h>
#include "lesson.hpp"
#include<iostream>
#include "burtgel.hpp"

lesson::lesson( ){
    name = new char[20];
    strcpy(name, " ");
    
    
    
    teacher bagsh;
    
    student oyutan[10];
};
lesson::~lesson(){
    delete[] name;
}

lesson::lesson( char *nam, teacher bag, student stn[], int n){
    delete[] name;
    name = new char[strlen(nam)+1];
    strcpy(name, nam);
    
    bagsh = bag;
    student oyutan[n];
    for(int i=0; i<n; i++)
        oyutan[i] = stn[i];
}

void lesson::setName(char stn[]){
    delete name;
    name = new char[strlen(stn)+1];
    strcpy(name,stn);
}

char* lesson::getName(){
    return name;
}


void lesson::setSedev(string stn, int x4){
    sedev[x4] = stn;
}

string lesson::getSedev(int x4){
    return sedev[x4];
}

