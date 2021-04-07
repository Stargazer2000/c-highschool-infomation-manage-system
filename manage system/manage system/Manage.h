#pragma once
#include <iostream>
#include<fstream>
#include"people.h"
#include"student.h"
#include"teacher1.h"
#include"teacher2.h"
#define FILENAME "data.txt"
using namespace std;
class manage
{
public:
	void add_new();//添加新人员
	void print_all();//打印特定学院全部人员
	void sreach();//按卡号搜索
	void delet();//删除
	void menu();//菜单
	void save();//退出保存
	bool check(int ID, int t, people** mid);//检查输入学号是否重复
	~manage();
private:
	int all_people_num = 0;
	people** Array = NULL;
};