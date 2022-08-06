#include<iostream>
using namespace std;
inline int odd_avg(int a[], int n){
	int i,s=0,p=0,z;
	for(i=0;i<n;i++){
		if(a[i]%2!=0){
			s+=a[i];
			p++;
		}
	}
	z=s/p;
	return z;
	}
int main(){
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"aripmetik dundaj "<<odd_avg(a,n);
}
