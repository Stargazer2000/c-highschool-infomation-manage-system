#pragma once
#include <iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include"people.h"
#include"student.h"
#include"teacher1.h"
#include"teacher2.h"
#define FILENAME "data.txt"
using namespace std;
static int all_people_num_change = 0;
class manage
{
public:
	void getinfo();//从文件读取
	void add_new();//添加新人员
	void print_all_department();//打印特定职位全部人员
	void print_all_depart();//打印特定学院全部人员
	void sreach();//按卡号搜索
	void salary_change();//对工资的整体调整
	void delet();//删除
	void menu();//菜单
	void save();//退出保存
	bool check(int ID, int t, people** mid);//检查输入学号是否重复
	~manage();
private:
	int all_people_num = 0;
	people** Array = NULL;
};