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
	void add_new();//�������Ա
	void print_all();//��ӡ�ض�ѧԺȫ����Ա
	void sreach();//����������
	void delet();//ɾ��
	void menu();//�˵�
	void save();//�˳�����
	bool check(int ID, int t, people** mid);//�������ѧ���Ƿ��ظ�
	~manage();
private:
	int all_people_num = 0;
	people** Array = NULL;
};