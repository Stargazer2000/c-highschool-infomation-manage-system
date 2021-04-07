#pragma once
#include<iostream>
#include<cstring>
using namespace std;
class people
{
public:
	int ID;
	string name;
	int sex;
	int department;
	string depart;
	int year;
	string subject;
	double salary;
	virtual void show_info() = 0;
	virtual string get_apartment_info() = 0;
private:
	
};