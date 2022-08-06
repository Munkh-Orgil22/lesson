#include<iostream>
using namespace std;
void change(int *a, int *b);
int main(){
  int i,j;
  cout<< "ehnii i: "; 
  cin>>i;
  cout<< "ehnii j: "; 
  cin>>j;
  
  change(&i, &j);
	cout<< "daraagin i: "<<i; 
  	cout<< "\ndaragin j: "<<j; 

  
}
void change(int *a, int *b){
   int s=*a;
   *a=*b;
   *b=s;
}
