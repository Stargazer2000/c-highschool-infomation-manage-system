#pragma once
#include<iostream>
using namespace std;
#include"people.h"
class teacher1 :public people
{
public:
	teacher1(int, string, int, string, string, int);
	virtual void show_info();
	virtual string get_apartment_info();
private:
	
};
