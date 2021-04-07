#pragma once
#include<iostream>
using namespace std;
#include"people.h"
class teacher2 :public people
{
public:
	teacher2(int, string, int, string, double);
	virtual void show_info();
	virtual string get_apartment_info();
private:
	
};
