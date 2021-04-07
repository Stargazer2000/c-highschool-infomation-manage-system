#pragma once
#include<iostream>
using namespace std;
#include"people.h"
class student :public people
{
public:
	student(int, string, int, string, int) ;
	virtual void show_info();
	virtual string get_apartment_info();
private:
	
};
