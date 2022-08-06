//
//  teacher.cpp
//  burtgel
//
//  Created by MacUser on 11/9/18.
//  Copyright © 2018 MacUser. All rights reserved.
//
#include<iostream>
#include "teacher.hpp"
teacher::teacher(){
    name = new char[20];
    strcpy(name, " ");
    
    title = new char[20];
    strcpy(title," ");
    
    id = new char[20];
    strcpy(id, " ");
    };

teacher::~teacher(){
    delete[] name;
    delete[] id;
    delete[] title;
}
teacher::teacher(char *nam, char *tit, char *ida ){
    delete[] name;
    name = new char[strlen(nam)+1];
    strcpy(name, nam);
    
    delete[] title;
    title = new char[strlen(tit)+1];
    strcpy(title, tit);
    
    delete[] id;
    id = new char[strlen(id)+1];
    strcpy(id, ida);
}

void teacher::setName(char stn[]){
    delete[] name;
    name = new char[strlen(stn)+1];
    strcpy(name, stn);
}

void teacher::setId(char stn[]){
    delete[] id;
    id = new char[strlen(stn)+1];
    strcpy(id, stn);
}

void teacher::setTitle(char stn[]){
    delete[] title;
    title = new char[strlen(stn)+1];
    strcpy(title, stn);
}

char* teacher::getName(){
    return name;
}

char* teacher::getId(){
    return id;
}

char* teacher::getTitle(){
    return title;
}
