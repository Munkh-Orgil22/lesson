#include<iostream>
using namespace std;
int main(){
	int n,i,m,s;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	m=a[0];
	s=a[0];
	for(i=1;i<n;i++){
		if(m>a[i])
			m=a[i];
	}
	for(i=1;i<n;i++){
		if(s<a[i])
		s=a[i];
	}
	cout<<"max "<<s<<"min  "<<m;
}
