#include<iostream>
using namespace std;
#include"Manage.h"
int main()
{
	manage list;
	list.getinfo();
	cout << "欢迎使用高校信息管理系统1.0版本" << endl;
	while (1)
	{
		list.menu();
	}
}