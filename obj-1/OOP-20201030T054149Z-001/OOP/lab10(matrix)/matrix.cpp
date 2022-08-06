//
//  matrix.cpp
//  matrix
//
//  Created by MacUser on 12/5/18.
//  Copyright © 2018 MacUser. All rights reserved.
//

#include "matrix.hpp"
#include <iostream>
using namespace std;
//anhdagch baiguulagch
matrix::matrix(){
    r = 0;
    c = 0;
    mat = new float*[r];
    for(int i=0;i<r;i++)
        mat[i] = new float[c];
}

//parametrtei baiguulagch
//garaas mor, baganiin toog avna
//garaas avsan utguudtai matrix butsna
matrix::matrix(int row, int col){
    //baiguulagchaar dynamic husnegt sanah oi deer uusgeh
    r = row;
    c = col;
    mat = new float*[r];
    for(int i=0; i<r; i++)
        mat[i] = new float[c];
}

//tuhain matrix iin heden mor baigaag butsaana
int matrix::getRows(){
    return r;
}

//tuhain matrix iin heden bagana baigaag butsaana
int matrix::getCols(){
    return c;
}

//matrix-iin utguudiig 0 bolgoh function
void matrix::initmatrix(){
    //anhnii utga onooh
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            mat[i][j] = 0;
        }
    }
}

//matrix-d garaas utga avah function
void matrix::setMat(){
    //utga onooh function
    for(int i=0; i<r; i++){
        for(int j=0; j<c;j++){
            cin>>mat[i][j];
        }
    }
}

//ehleed mor daraa ni baganin utgiig avsanaar tuhain matrix d hargalzah utgiig ni avna
int matrix::getValue(int i, int j){
    //hargalzah matrix iig butsaah
    return mat[i][j];
}
/**
 2 matrix nemdeg func
 a ni matrix turliin object baina
 Garaltaar tuhain this matrix deer orj irsen a-matrix 2n niilberiig butsaana
 **/

matrix matrix::operator+(matrix a){
    if(r == a.r && c == a.c){
        //niilber hadgalah object
        matrix tmp(r,c);
        //bagana moroor guuj niilber oloh
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                tmp.mat[i][j] = mat[i][j] + a.mat[i][j];
            }
        }
        return tmp;
    }
    return a;
}

//Oroltoor hasah gj baigaa matrix avna
//Garaltaar tuhain this matrix deer orj irsen matrix 2iin ylgavar garna
matrix matrix::operator-(matrix a){
    if(r == a.r && c == a.c){
        //ylgavar hadgalah object
        matrix tmp(r,c);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                tmp.mat[i][j] = mat[i][j] - a.mat[i][j];
            }
        }
        return tmp;
    }
    return a;
}

//Oroltoor utga shiljiiulj baigaa matrix avna
//tuhain matrixiin utgiig butsaana
matrix matrix::operator=(matrix a){
    if(r == a.r && c == a.c){
        matrix tmp(r,c);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                tmp.mat[i][j] = a.mat[i][j];
            }
        }
        return tmp;
    }
    return a;
}

//Oroltoor parametrdee urjuulj baigaa matrix avna
//2 matrix iin urjveriig butsaana
matrix matrix::operator*(matrix a){
    matrix tmp(r, c);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            float sum = 0;
            for(int k =0; k<c; k++)
                sum = sum+mat[i][k] * a.mat[k][j];
            tmp.mat[i][j] = sum;
        }
    }
    return tmp;
}

//oroltoor matirx avna
//orj irsen matrixiin utgiig += operatoriin omnoh matrix 2n niilber garna
void matrix::operator += (matrix a){
    //bagana moroor guuj davtalt oloh
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            mat[i][j] = mat[i][j] + a.mat[i][j];
        }
    }
}

//oroltoor -= hiih matrix avna
// -= omnoh matrix aas oroltoor irsen matrix iin hassan utga butsna
void matrix::operator -= (matrix a){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            mat[i][j] = mat[i][j] - a.mat[i][j];
        }
    }
}

//bagana moroor guuj matrix iin element buriin utgiig 1eer nemeh
void matrix::operator++(void){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            mat[i][j]++;
        }
    }
}

// -- operatriig matrix deer bichej oghod tuhain matrixiin buh utga -1 eer horogdono
void matrix::operator--(void){
    //matrix iin hargalzah utgiig -1 eer horogduulah
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            mat[i][j]--;
        }
    }
}

//parametreer orj irsen matrixiin utgiig a matrixiin hargalzah utgaar urjuuleh
void matrix::operator*=(matrix a){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            for(int k=0; k<c; k++)
            mat[i][j] = mat[k][j] * a.mat[i][j];
        }
    }
}
//matrix iin utgiig haruulah
void matrix::show(){
    //hevleh
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
//matrix deer ! iig omno bichej oghod matrixiin mor , bagana 2n bair soligdono
void matrix::operator!(void){
    //matrixiin mor bagana 2n bairiig solih
    matrix tmp(r,c);
    for(int i=0; i<r;i++){
        for(int j=0; j<c; j++){
            tmp.mat[i][j] = mat[i][j];
        }
    }
    for(int i=0; i<r;i++){
        for(int j=0; j<c; j++){
            mat[i][j] = tmp.mat[j][i];
        }
    }
}
//matrix deer bodit too nemeh
void matrix::operator+(float a){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            mat[i][j]+=a;
        }
    }
}
