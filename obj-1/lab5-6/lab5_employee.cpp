#include<iostream>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;

class employee{
	private:
		int id;
		char *name;
		char *position;
		float worked_time;
		int zahirliin_tsalin();
	public:
		employee();
		employee(int a, char *b, char *c, float d);
		void set_id(int a);
		int get_id();
		void set_name(char *a);
		char* get_name();
		void set_position(char *a);
		char* get_position();
		void set_worked_time(float a);
		float get_worked_time();
		int tsalin_bodoh();
		~employee();

	};
employee :: employee(){
	id = 0;
	name = new char[2];
	strcpy(name, "");
	position = new char[7];
	strcpy(position, "ajilchin");
	worked_time = 0;
	cout<<id<<"\t"<<name<<"\t"<<position<<"\t"<<worked_time<<endl;
}
employee :: employee(int a, char *b, char *c, float d){
	id=0;
	name = new char (strlen(name));
	strcpy(name, b);
	position = new char(strlen(position));
	strcpy(position, c);
	worked_time = 0;
	cout<<id<<"\t"<<name<<"\t"<<position<<"\t"<<worked_time<<endl;
}
employee :: ~employee(){
	delete name, position;
	cout<<"object deleted\n";
}
void employee :: set_id(int a){
	id=a;
}

int employee :: get_id(){
	return id;
}

void employee :: set_name(char *a){
	name = new char(strlen(a)+1);
	strcpy(name, a);
}

char* employee :: get_name(){
	return name;
}

void employee :: set_position(char *a){
	position = new char(strlen(a)+1);
	strcpy(position, a);
}

char*  employee :: get_position(){
	return position;
}

void employee :: set_worked_time(float a){
	worked_time=a;
}

float employee :: get_worked_time(){
	return worked_time;
}

int employee :: zahirliin_tsalin(){
	return worked_time*22*5000;
}

int employee :: tsalin_bodoh(){
	int a, b;
	if(strcmp(position, "zahiral")!=0){
		a=worked_time*22;
		b=a*3750;
		return b;
	}
	else
		 return zahirliin_tsalin();
}

void get_data(employee a[], int h){
	int i, j, id, x;
	float b;
	char name[20], position[15];
	for(i=0; i<h; i++){
		cout<<"Ajilchnii Id: ";
		cin>>id;
		for(j=0; j < i; j++){
			if(id==a[j].get_id()){
				cout<<"ID davhardsan";
				exit(1);
			}
		}
			a[i].set_id(id);
		cout<<"Ajilchnii ner: ";
		cin>>name;
		a[i].set_name(name);
		cout<<"Ajilchnii alban tushaal: ";
		cin>>position;
		a[i].set_position(position);
		cout<<"Ajilchnii ajillasan tsag: ";
		cin>>b;
		a[i].set_worked_time(b);
	}
}

void print(employee a[], int h){
	int i;
	for(i=0; i<h; i++){
		cout<<a[i].get_id()<<"\t";
		cout<<a[i].get_name()<<"\t";
		cout<<a[i].get_position()<<"\t\t";
		cout<<a[i].get_worked_time()<<"\t";
		cout<<a[i].tsalin_bodoh()<<"\n";
	}
}

void sort_name(employee *b[], int h){
	int i, j;
	for(i=0; i<h-1; i++){
		for(j=0; j<h-i-1; j++){
			if(strcmp(b[j]->get_name(), b[j+1]->get_name())==1){
				employee *t;
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	}
	cout<<"sorted name: "<<endl;
	for(i=0; i<h; i++){
		cout<<b[i]->get_id()<<"\t";
		cout<<b[i]->get_name()<<"\t";
		cout<<b[i]->get_position()<<"\t\t";
		cout<<b[i]->get_worked_time()<<"\t";
		cout<<b[i]->tsalin_bodoh()<<"\n";
	}
}



int main(){
	int h;
	cout<<"Heden ajilchin burtgeh ve: "<<endl;
	cin>>h;
	employee a[h];
	get_data(a, h);
	employee *b[h];
	int i;
	for(i=0; i<h; i++)
		b[i]=&a[i];
	sort_name(b, h);
}




