#include<iostream>
using namespace std;
#include"Manage.h"
int main()
{
	manage list;
	list.getinfo();
	while (1)
	{
		list.menu();
	}
}