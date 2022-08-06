#include<iostream>
#include<string.h>
using namespace std;
class worker{
public:
  char *name;
  char *pos;
  int id;
  float time1;
  worker();
  worker( char *n,  char *p, float b);
  ~worker();
  void read();
  bool addtime();
  float pay();
  void print();
};
worker::worker(){
  name = new char[20];
  strcpy(name,"tester");
  pos = new char[10];
  strcpy(pos,"ajil");
  id = 0;
  time1=0;
}
worker::worker( char *n, char *p, float b){
  name = new char[strlen(n)+1];
  strcpy(name, n);
  pos = new char[strlen(n)+1];
  strcpy(pos, p);
  time1 = b;
  id = 0;
}
worker::~worker(){
  cout<<"\n\tAjilchin "<<name<< " ustgagdlaa";
  delete name;
  delete pos;
}
void worker::read(){
  cout<<"\n\tEnter employee name: ";
  cin>>name;
  cout << "\n\tEnter employee id: ";
  cin >> id;
  cout<<"\n\tEnter employee position: ";
  cin>>pos;
  cout<<"\n\tEnter worked time: ";
  cin>>time1;
}
bool worker::addtime(){
  int b;
  cout<<"nemelt tsagaa oruulna uu ?";
  cin>>b;
  if(b>0 && b<=24){
    time1+=b;
    return 1;
  }
  else
    return 0;
}
float worker::pay(){
  int a;
  a=strcmp(pos,"darga");
  if(a==0)
    return time1*12000+time1*3000;
  else
    return time1*12000;
}
void worker::print(){
  cout<<"\n"<<id<<"\t"<<name<<"\t"<<pos<<"\t"<<time1<<"\t"<<pay();
}
void sort(worker a[], int b){
  int i,j;
  worker t;
  for(i=1;i<b;i++){
    for(j=1;j<b;j++){
      if(strcmp(a[j-1].name , a[j].name)>0){
         t=a[j-1];
         a[j-1]=a[j];
         a[j]=t;
      }
   
    }
  }
}
int main(){
  int i,b=3;
  worker a[b];
  for(i=0; i<b; i++){
    cout<<"\n Enter details of "<< i+1<<"th worker";
    a[i].read();
    a[i].addtime();
  }
  for(i=0;i<b;i++){
    a[i].print();
  }
  sort(a,b);
  cout<<"\n Eremblegdsen ajilchid :\n";
  for(i=0;i<b;i++){
    a[i].print();
  }
}
