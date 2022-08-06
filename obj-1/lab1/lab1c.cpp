#include<iostream>
using namespace std;
inline int total(int a[], int n){
	int i,s=0;
	for(i=0; i<n; i++){
		if(a[i]%2==0)
			s++;
	}
	return s;
}
int main(){
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"tegsh elementuudiin too: "<< total(a,n);

}
