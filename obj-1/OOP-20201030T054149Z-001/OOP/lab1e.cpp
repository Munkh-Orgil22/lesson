#include<iostream>
using namespace std;
inline int num(int s, int *a){
	int i=0,p;
	while(s>0){
		*(a+i)=s%10;
		s=s/10;
		i++;
	}
	return i;
}
int main(){
	int s,j,d;
	int a[20];
	cin>>s;
	d=num(s,a);
	cout<<"orongiin too"<<num(s,a);
	cout<<"tsipruud";
	for(j=0;j<d;j++)
		cout<<a[j];
}
