#include"Manage.h"
void manage::menu()
{
	cout << "欢迎使用高校信息管理系统1.0版本" << endl;
	cout << "1.添加新的人员" << endl;
	cout << "2.删除一个人员" << endl;
	cout << "3.查找某个人员" << endl;
	cout << "4.显示某学院所有人员" << endl;
	cout << "5.退出系统" << endl;
	int opreation;
	cin >> opreation;
	switch (opreation)
	{
	case 1:
		this->add_new();
		break;
	case 2:
		this->delet();
		break;
	case 3:
		this->sreach();
		break;
	case 4:
		this->print_all();
		break;
	default:
	{
		save();
		exit(0);
		break;
	}
	}
}
void manage::save()
{
	for (int t = 0;t < 3;t++)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::out);
		ofs << this->all_people_num << endl;
		for (int i = 0;i < this->all_people_num;i++)
		{
			if (this->Array[i]->department == 1 && t == 0)//学生卡号, 姓名, 性别, 学院, 入学年份
				ofs << this->Array[i]->ID << " "
				<< this->Array[i]->name << " "
				<< this->Array[i]->sex << " "
				<< this->Array[i]->depart << " "
				<< this->Array[i]->year << endl;
			else if (this->Array[i]->department == 2 && t == 1)//教师卡号, 姓名, 性别, 学院, 教授科目, 教龄
				ofs << this->Array[i]->ID << " "
				<< this->Array[i]->name << " "
				<< this->Array[i]->sex << " "
				<< this->Array[i]->depart << " "
				<< this->Array[i]->subject << " "
				<< this->Array[i]->year << endl;
			else if (this->Array[i]->department == 3 && t == 2)//卡号, 姓名, 性别, 部门, 每月工资(带有两位小数)
				ofs << this->Array[i]->ID << " "
				<< this->Array[i]->name << " "
				<< this->Array[i]->sex << " "
				<< this->Array[i]->depart << " "
				<< this->Array[i]->salary << endl;
		}
		ofs.close();
	}
}
void manage::add_new()
{
	cout << "请输入添加的人员的类别：" << endl;
	cout << "1.学生" << endl << "2.教师" << endl << "3.行政人员" << endl;
	int depart = 0;
	cin >> depart;
	cout << "请输入添加的人员的人数：";
	int num = 0;
	cin >> num;
	if (num > 0)
	{
		int new_size = this->all_people_num + num;
		people** newspace = new people * [new_size];
		if (this->Array != NULL)
		{
			for (int i = 0;i < this->all_people_num;i++)
			{
				newspace[i] = this->Array[i];
			}
		}
		for (int i = 0;i < num;i++)
		{
			people* man = NULL;
			switch (depart)
			{
			case 1://学生卡号, 姓名, 性别, 学院, 入学年份
			{
				int ID;
				string name;
				int sex;
				string department;
				int year;
				printf("输入第%d个学生卡号：\n", i + 1);
				while (1)
				{
					cin >> ID;
					if (check(ID, i, newspace)) {
						cout << "卡号重复！请重新输入！" << endl;
					}
					else break;
				}
				printf("输入第%d个学生姓名：\n", i + 1);
				cin >> name;
				printf("输入第%d个学生性别：\n", i + 1);
				printf("1.男性\n2.女性\n");
				cin >> sex;
				printf("输入第%d个学生学院：\n", i + 1);
				cin >> department;
				printf("输入第%d个学生入学年份：\n", i + 1);
				cin >> year;
				man = new student(ID, name, sex, department, year);
				man->department = depart;
				break;
			}
			case 2://教师卡号, 姓名, 性别, 学院, 教授科目, 教龄
			{
				int ID;
				string name;
				int sex;
				string department;
				string sub;
				int year;
				printf("输入第%d个教师卡号：\n", i + 1);
				while (1)
				{
					cin >> ID;
					if (check(ID, i, newspace)) {
						cout << "卡号重复！请重新输入！" << endl;
					}
					else break;
				}
				printf("输入第%d个教师姓名：\n", i + 1);
				cin >> name;
				printf("输入第%d个教师性别：\n", i + 1);
				printf("1.男性\n2.女性\n");
				cin >> sex;
				printf("输入第%d个教师学院：\n", i + 1);
				cin >> department;
				printf("输入第%d个教师教授科目：\n", i + 1);
				cin >> sub;
				printf("输入第%d个教师教龄：\n", i + 1);
				cin >> year;
				man = new teacher1(ID, name, sex, department, sub, year);
				man->department = depart;
				break;
			}
			case 3://卡号, 姓名, 性别, 部门, 每月工资(带有两位小数)
			{
				int ID;
				string name;
				int sex;
				string department;
				double salary;
				printf("输入第%d个行政人员卡号：\n", i + 1);
				while (1)
				{
					cin >> ID;
					if (check(ID, i, newspace)) {
						cout << "卡号重复！请重新输入！" << endl;
					}
					else break;
				}
				printf("输入第%d个行政人员姓名：\n", i + 1);
				cin >> name;
				printf("输入第%d个行政人员性别：\n", i + 1);
				printf("1.男性\n2.女性\n");
				cin >> sex;
				printf("输入第%d个行政人员部门：\n", i + 1);
				cin >> department;
				printf("输入第%d个行政人员工资：\n", i + 1);
				cin >> salary;
				man = new teacher2(ID, name, sex, department, salary);
				man->department = depart;
				break;
			}
			default:
				cout << "输入错误！" << endl;
				break;
			}
			newspace[this->all_people_num + i] = man;
		}
		delete[] this->Array;
		this->Array = newspace;
		this->all_people_num = new_size;
	}
}

void manage::print_all()
{

}

void manage::sreach()
{
}
bool manage::check(int ID, int t, people** mid)
{
	for (int i = 0;i < this->all_people_num + t;i++)
	{
		if (ID == mid[i]->ID) return 1;
	}
	return 0;
}
void manage::delet()
{
}
manage::~manage()
{
	if (this->Array != NULL)
	{
		delete[] this->Array;
		this->Array = NULL;
	}
}
