#include <iostream>
#include<string>
#include "teacher.hpp"
#include "student.hpp"
#include "lesson.hpp"
#include "burtgel.hpp"

using namespace std;
int main() {
    int i,n,p;
    char k[4],num[6];
    cout<<"Heden oyutan burtgehee oruulna uu: ";
    cin>>n;
    student a[n];
    for(i = 0; i<n; i++){
        //ner onooj ogj bn
        k[0] = (char)(65+i);
        k[1] = (char)(97+i);
        k[2] = (char)(108+i);
        a[i].setName(k);
        //id onooj ogj bn
        num[0] = (char)66;
        num[1] = '1';
        num[2] = '1';
        num[3] = '8';
        num[4] = (char)(48+i);
        a[i].setId(num);
        
        a[i].setGrade(1);
        a[i].setGpa(0);
    }
    
    
    cout<<"heden bagshtai bh we";
    cin>>p;
    teacher b[p];
    char l1[5],l2[7],l3[3];
    for(i = 0;i < p; i++){
        //bagsh nart ner onooh
        l1[0] = (char)69;
        l1[1] = (char)99;
        l1[2] = (char)105;
        l1[3] = (char)96;
        l1[4] = (char)99;
        b[i].setName(l1);
        //buh bagsh nar phD bh
        l2[0] = (char)112;
        l2[1] = (char)104;
        l2[2] = (char)68;
        b[i].setTitle(l2);
        //bagsh nariin id daraalsan bh
        l3[0] = 0;
        l3[1] = 0;
        l3[2] = i;
        b[i].setId(l3);
    }
    cout<<endl;
    cout<<"Surj baigaa buh oyutnuudiin medeelel"<<endl;
    for(i = 0; i <n ; i++){
        cout<<"Ner "<<a[i].getName()<<"\t    ID "<<a[i].getId()<<endl;
    }
    
    
    cout<<"heden hicheel oruulah we:";
    int x, x1 = 0;
    char hich[40];
    cin>>x;
    int x8[x];
    //hicheel bolon oyutanii toog hadgalah x8;
    lesson c[x];
    for(i = 0; i < x; i++){
        cout<<i+1<<" deh hicheeliin neree oruulna uu";
        cin>>hich;
        c[i].setName(hich);
    }
    int j=-1,too = 0,d,t;
    while( j!=0 ){
        cout<<endl;
        cout<<"1. hed dugaartai hicheeld oyutnuudiin medeelliig oruulah bol-1\n 2. hed dugaartai hicheeliig songoh, bolon oyutnuudiin irts hicheeliin medeelliig oruulah bol-2\ngarah - 0\n";
        cin>>j;
        if(j == 1){
            cout<<"hed dugaartai hicheel songoh we ?\n";
            cin>>x1;
            x1 = x1-1;
            cout<<"ene hicheeliig heden oyutan uzehiig oruulna uu ?";
            cin>>too;
            x8[x1] = too;
            //hicheel uzeh oyutnuudiin toog hadgaah x8;
            cout<<"ene hicheeliig uzeh oyutnii idiig oruulna uu ?\n";
            for(d = 0; d<too; d++){
                char check_student[20];
                cin>>check_student;
                for(t = 0; t<n; t++){
                    if(strcmp(check_student, a[t].getId()) == 0){
                        c[x1].oyutan[d] = a[t];
                        //tuhain hicheel oyutaniig oruulj ogoh heseg;
                    }
                }
            }
            //hicheel uusej oyutan orhod irts uussen baih;
            cout<<"oyutnuudiig~ "<<c[x1].getName()<<" ~hicheeld amjilttai huullaa\n";
        }
        
        if( j == 2){
            cout<<"hed dugaartai hicheel songoh we ?";
                cin>>x1;
            x1=x-1;
            cout<<"heden udaagiin orolttei we?";
                int x3;
            cin>>x3;
                c[x1].sedev[x3];
            for(i = 0; i < x3; i++){
                string sed;
                cout<<"sedviin neree oruulna uu:";
                cin>>sed;
                c[x1].setSedev(sed, i);
                cout<<"\nirts burtgeh";
                int ir;
                cout<<"oyutnuudiin ners bolon id\n";
                for(ir = 0; ir<x8[x1]; ir++){
                    cout<<ir+1<<"."<<c[x1].oyutan[ir].getName()<<"\t"<<c[x1].oyutan[ir].getId()<<endl;
                        c[x1].regist[i].irts(ir);

                }
                }
            }
        }
    

    cout<<"\nhed dugeer hicheeliin burtgeliig harah we?";
    cin>>x1;
    x1 = x1-1;
    int y = x8[x1];
    for(i = 0; i<y; i++){
        cout<<c[x1].oyutan[i].getName()<<" nii irtsiin medeelel"<<endl;
        int irsen = 0, tas = 0, ovchtei = 0, cholootei = 0;
        for(j = 0; j<y; j++){
            if(c[x1].regist[i].getIrts(j) == 1)
                irsen++;
            if(c[x1].regist[i].getIrts(j) == 2)
                tas++;
            if(c[x1].regist[i].getIrts(j) == 3)
                ovchtei++;
            if(c[x1].regist[i].getIrts(j) == 4)
                cholootei++;
        }
        cout<<" irsen = "<<irsen<<" tas = "<<tas<<" ovchtei = "<<ovchtei<<" cholootei = "<<cholootei<<endl;
        
    }

    
}
