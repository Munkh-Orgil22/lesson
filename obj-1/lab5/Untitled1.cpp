#include <iostream>
  using namespace std;
	int add(int &x,int &y){
		x=x+y;
		return x;
	}
	void main()
	{
		int a=-5,b=4;
		d=add(a,b);
		cout<<a<<","<<d;
	}
  
