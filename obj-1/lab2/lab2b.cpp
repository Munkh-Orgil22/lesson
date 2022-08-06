#include<iostream>
using namespace std;
void change(int &x,int &y){
  int s;
  s=x;
  x=y;
  y=s;
}
int main(){
  int a, b;
  cin>>a;
  cin>>b;
  cout<<"ehnii a= "<<a<<endl;
  cout<<"ehnii b= "<<b<<endl;
  change(a,b);
  cout<<"a= "<<a<<endl;
  cout<<"b= "<<b<<endl;
}
