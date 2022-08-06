#include<iostream>
using namespace std;
#define max(a,b,c) (a>b) ? (a>c?a:c) : (b > c ? b : c)
int main(){
	int a,b,c,z;
	cin>>a>>b>>c;
	z=max(a,b,c);
	cout<<z;
}
