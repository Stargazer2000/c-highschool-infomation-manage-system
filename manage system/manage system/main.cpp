#include<iostream>
using namespace std;
#include"Manage.h"
int main()
{
	manage list;
	list.getinfo();
	cout << "��ӭʹ�ø�У��Ϣ����ϵͳ1.0�汾" << endl;
	while (1)
	{
		list.menu();
	}
}