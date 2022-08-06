//
//  main.cpp
//  shape
//
//  Created by MacUser on 11/20/18.
//  Copyright © 2018 MacUser. All rights reserved.
//


#include "shape.hpp"
#include "TwoDimen.hpp"
#include "circle.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include <iostream>
#include"toirog.hpp"

using namespace std;

int main() {
    cout<<"~~~~~~~~~~~~~~~~~~~~~CircLe~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
   circle toirog1[11];
    
    int x=5, y=5, r=2, i, j;
    for(i = 0, j = r ; i<10; i++, j++){
        circle curr(x,y,j);
        toirog1[i] = curr;
    }
    
    cout<<"eremblegdeegue: "<<endl;
    for(i = 0; i<10; i++)
        cout<<toirog1[i].findS()<<" ";
    
    for(i = 1; i < 10; i++){
        circle key = toirog1[i];
        int j = i-1;
        while( j >= 0 && toirog1[j].findS() < key.findS() ){
            toirog1[j+1] = toirog1[j];
            j = j-1;
        }
        toirog1[j+1] = key;
    }
    
    cout<<"\nEremblegdsen: "<<endl;
    for(i = 0; i<10; i++)
        cout<<toirog1[i].findS()<<" ";
    cout<<"\n Name: "<<toirog1[1].getColor();
    cout<<"\n GetX: "<<toirog1[1].getX();
    cout<<"\n GetY: "<<toirog1[1].getY();
    cout<<"\n GetR: "<<toirog1[1].getR();
    
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~SquaRe~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    
    square k2[11];
    x = 10; y = 10; r = 4;
    for(i = 0, j = r ; i<10; i++, j++){
        square curr(x,y,j);
        k2[i] = curr;
    }
    cout<<"eremblegdeegue: "<<endl;
    for(i = 0; i<10; i++)
        cout<<k2[i].findS()<<" ";
    
    for(i = 1; i < 10; i++){
        square key = k2[i];
        int j = i-1;
        while( j >= 0 && k2[j].findS() < key.findS() ){
            k2[j+1] = k2[j];
            j = j-1;
        }
        k2[j+1] = key;
    }
    cout<<"\nEremblegdsen: "<<endl;
    for(i = 0; i<10; i++)
        cout<<k2[i].findS()<<" ";
    cout<<"\n Name: "<<k2[1].getColor();
    cout<<"\n GetX: "<<k2[1].getX();
    cout<<"\n GetY: "<<k2[1].getY();
    
    
    
    
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~TriangLe~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    triangle t3[11];
    x = 10; y = 10; r = 3;
    for(i = 0, j = r ; i<10; i++, j++){
        triangle curr(x,y,j);
        t3[i] = curr;
    }
    cout<<"eremblegdeegue: "<<endl;
    for(i = 0; i<10; i++)
        cout<<t3[i].findS()<<" ";
    
    for(i = 1; i < 10; i++){
        triangle key = t3[i];
        int j = i-1;
        while( j >= 0 && t3[j].findS() < key.findS() ){
            k2[j+1] = k2[j];
            j = j-1;
        }
        t3[j+1] = key;
    }
    cout<<"\nEremblegdsen: "<<endl;
    for(i = 0; i<10; i++)
        cout<<t3[i].findS()<<" ";
    
    cout<<"\n getX: "<<t3[1].getX();
    cout<<"\n getY: "<<t3[1].getY();
    
    
    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~toirog~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    x=8; y=8; r=5;
    toirog t1(x,y,r);
    cout<<"\n name: "<<t1.getColor();
    cout<<"\n X: "<<t1.getX();
    cout<<"\n Y: "<<t1.getY();
    
    
    return 0;
    
}
