//
//  main.cpp
//  student
//
//  Created by MacUser on 10/25/18.
//  Copyright © 2018 MacUser. All rights reserved.
//


#include <iostream>
#include"student.hpp"
#include<string>
using namespace std;
void sort_name(student *a[], int n){
    int i,j;
    student *tmp;
    // tur oi
    for(i=0;i<n;i++){
        for(j=1;j<n-i;j++){
            if((a[j-1]->after(*(a[j])))==1){
                //2 object iig jishih uildel
                tmp=a[j-1];
                a[j-1]=a[j];
                a[j]=tmp;
                }
            }
        }
    }
void sort_grade(student *a[], int n){ 
    int i,j;
    student *tmp;
    for(i=0;i<n;i++){
        for(j=1;j<n-i;j++){
            if(a[j-1]->greatThan(*(a[j]))==1){
//greatThan zaaltan object baga bol urdah object ni solih uildel
                tmp=a[j-1];
                a[j-1]=a[j];
                a[j]=tmp;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, i, j,gpa,grade,member=0;
    char name[20], id[16];
    cout<<"heden oyutan oruulah aa bichne uu : "<<endl;
    cin>>n;
    student *a[n];
    for(i=0; i<n; i++){
        member++; // Static ogogdoloor object tooloh
        a[i] = new student();
        cout<<"\n Enter details of "<< i+1<<"th student";
        cout<<"\n\tEnter student name: ";
        cin>>name;
        a[i]->setName(name);
        cout<<"\n\tEnter student Id: ";
        cin>>id;
        a[i]->setId(id);
        cout<<"\n\tEnter student Grade: ";
        cin>>grade;
        a[i]->setGrade(grade);
        cout<<"\n\tEnter student GPA: ";
        cin>>gpa;
        a[i]->setGpa(gpa);
        }
   sort_name(a,n);
    cout<<"Nereer eremblegdsen : "<<endl;
    cout<<"\t\tName\t\tId\t\tgrade\tGPA"<<endl;
    for(j=0;j<n;j++){
        cout<<"\t\t"<<a[j]->getName();
        cout<<"\t\t"<<a[j]->getId();
        cout<<"\t\t"<<a[j]->getGrade();
        cout<<"\t\t"<<a[j]->getGpa()<<endl;
    }
    sort_grade(a,n);
    cout<<"Grade eremblegdsen " <<endl;
    cout<<"\t\tName\t\tId\t\tgrade\tGPA";
    cout<<endl;
    for(j=0;j<n;j++){
        cout<<"\t\t"<<a[j]->getName();
        cout<<"\t\t"<<a[j]->getId();
        cout<<"\t\t"<<a[j]->getGrade();
        cout<<"\t\t"<<a[j]->getGpa()<<endl;
    }
    cout<<"\n "<<member<<" object uussen ";
    return 0;
}
