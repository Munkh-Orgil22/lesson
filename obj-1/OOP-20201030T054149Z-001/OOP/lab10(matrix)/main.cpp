//
//  main.cpp
//  matrix
//
//  Created by MacUser on 12/3/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#include <iostream>
#include "matrix.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    int i,j;
    cout<<"bagana moroo oruulna uu : ";
    cin>>i>>j;
    matrix obj1(i,j);
    obj1.initmatrix();
    obj1.setMat();
    
    matrix obj2(i,j);
    obj2.initmatrix();
    obj2.setMat();
    
    //2 matrix iig hoorond ni nemeh
    matrix obj3 = obj1 + obj2;
    cout<<"matrixiin niilber: \n";
    obj3.show();
    
    //2 matrix iig hoorond ni hasah
    matrix obj4 = obj1 - obj2;
    cout<<"Matrixiin ylgavar: \n";
    obj4.show();
    
    //2 matrixiig hoorond ni urjuueh
    matrix obj5 = obj1 * obj2;
    cout<<"Matrixiin urjiver: \n";
    obj5.show();
    
    //matrix iin buh utgiig +1 eer nemegduuleh
    ++obj5;
    cout<<"Matrixiin ++ : \n";
    obj5.show();
    
    //matrix iin buh utgiig -1 eer horogduulah
    --obj5;
    cout<<"Matrixiin -- \n";
    obj5.show();
    
    //obj5 deer obj4 iin utgiig nemeh
    obj5+=obj4;
    cout<<"Matrixiin += \n";
    obj5.show();
    
    //obj5 aas obj4 iin utgiig hasah
    obj5-=obj4;
    cout<<"Matrixiin -= \n";
    obj5.show();
    
    //obj5 iig obj4 oor urjuuleh
    obj5*=obj4;
    cout<<"Matrixiin *= \n";
    obj5.show();
    
    //obj5 iin mor baganiin utgiig solih
    !obj5;
    cout<<"Matrixiin urwuu \n";
    obj5.show();
    
    //matrix iin utguudiig togtmol toogoor nemegduuleh
    obj5+12.5;
    cout<<"Matrix deer too nemeh \n";
    obj5.show();
    return 0;
}
