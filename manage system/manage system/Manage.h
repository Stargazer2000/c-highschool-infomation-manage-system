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
	void getinfo();//���ļ���ȡ
	void add_new();//�������Ա
	void print_all_department();//��ӡ�ض�ְλȫ����Ա
	void print_all_depart();//��ӡ�ض�ѧԺȫ����Ա
	void sreach();//����������
	void salary_change();//�Թ��ʵ��������
	void delet();//ɾ��
	void menu();//�˵�
	void save();//�˳�����
	bool check(int ID, int t, people** mid);//�������ѧ���Ƿ��ظ�
	~manage();
private:
	int all_people_num = 0;
	people** Array = NULL;
};