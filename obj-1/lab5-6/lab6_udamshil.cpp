#include <iostream>
#include <math.h>
using namespace std;

class shape
{
	protected:
		int x;
		int y;
		char name;
	public:
		float findS();
		float perimeter();
		void showdata();
};

class twoDimen:public shape
{
	protected:
		int coordinate;
	public:
		void showdata();
};

class circle:public twoDimen, public shape
{
	protected:
		int radius;
	public:
		void showdata();
		float findS();
		float perimeter();
};
float circle::perimeter()
{
	return radius*3.14*2;
}
float circle::findS()
{
	return 3.14*radius*radius;
}
void circle::showdata()
{
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~CircLe~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "toirgiin radius:" << endl;
	cin >> radius;
	cout << "toirgiin urt:" << perimeter() << endl;
	cout << "toirgiin talbai:" << findS() << endl;
}

class square:public twoDimen, public shape
{
	protected:
		int tal;
	public:
		void showdata();
		float findS();
		float perimeter();
};
float square::perimeter()
{
	return 4*tal;
}
float square::findS()
{
	return tal*tal;
}
void square::showdata()
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~Square~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 	cout << "Kwadratiin tal:"<< endl;
 	cin >> tal;
 	cout << "Kwadratiin perimeter:" << perimeter() << endl;
 	cout << "Kwadratiin talbai:" << findS() << endl;
}

class triangle:public twoDimen, public shape
{
	protected:
		int tal;
	public:
		void showdata();
		float findS();
		float perimeter();
};
float triangle::perimeter()
{
	float p = tal+tal+tal; 
    return p;
}
float triangle::findS()
{
	float p = (tal+tal+tal)/2; 
    return sqrt(p*(p-tal)*(p-tal)*(p-tal));
}
void triangle::showdata()
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~Triangle~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 	cout << "Gurwaljnii tal:" << endl;
 	cin >> tal;
 	cout << "Gurwaljnii perimeter:" << perimeter() << endl;
 	cout << "Gurwaljnii talbai:" << findS() << endl;
}

int main()
{
	circle cir;
	square sq;
	triangle tr;
	cir.showdata();
	sq.showdata();
	tr.showdata();
}
