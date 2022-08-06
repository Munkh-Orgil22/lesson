//
//  burtgel.cpp
//  burtgel
//
//  Created by MacUser on 11/14/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#include"burtgel.hpp"
#include<iostream>
using namespace std;
void burtgel::irts(int k){
    cout<<"1.irsen 2.tas 3. ovchtei 4. cholootei";
    int l;
    cin>>l;
    burt[k] = l;
}

int burtgel::getIrts(int k){
    return burt[k];
}
