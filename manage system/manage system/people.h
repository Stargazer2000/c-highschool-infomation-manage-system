#pragma once
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class people
{
public:
	int ID;
	string name;
	int sex;
	int department;
	int depart;
	string depart_teacher3;
	int year;
	string subject;
	double salary;
	bool if_delect;
	string* depart_name1;
	void get_depart_name(string*);
	virtual void show_info() = 0;
	virtual string get_apartment_info() = 0;
private:

};