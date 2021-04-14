#include"Manage.h"
void manage::menu()
{
	cout << "请输入操作：" << endl;
	cout << "1.添加新的人员" << endl;
	cout << "2.删除一个人员" << endl;
	cout << "3.查找某个人员" << endl;
	cout << "4.显示某特定职位所有人员" << endl;
	cout << "5.显示某一学院所有人员" << endl;
	cout << "6.对行政人员工资的整体调整" << endl;
	cout << "7.退出系统" << endl;
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
		this->print_all_department();
		break;
	case 5:
		this->print_all_depart();
		break;
	case 6:
		this->salary_change();
		break;
	default:
	{
		save();
		exit(0);
		break;
	}
	}
	system("pause");
}
void manage::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	ofs << this->all_people_num+all_people_num_change << endl;
	for (int t = 0;t < 3;t++)
	{
		for (int i = 0;i < this->all_people_num;i++)
		{
			if (this->Array[i]->department == 1 && t == 0 && this->Array[i]->if_delect)//学生卡号, 姓名, 性别, 学院, 入学年份
				ofs << this->Array[i]->department << ' '
				<< this->Array[i]->ID << ' '
				<< this->Array[i]->name << ' '
				<< this->Array[i]->sex << ' '
				<< this->Array[i]->depart << ' '
				<< this->Array[i]->year << ' '
				<< this->Array[i]->if_delect << endl;
			else if (this->Array[i]->department == 2 && t == 1 && this->Array[i]->if_delect)//教师卡号, 姓名, 性别, 学院, 教授科目, 教龄
				ofs << this->Array[i]->department << ' '
				<< this->Array[i]->ID << ' '
				<< this->Array[i]->name << ' '
				<< this->Array[i]->sex << ' '
				<< this->Array[i]->depart << ' '
				<< this->Array[i]->subject << ' '
				<< this->Array[i]->year << ' '
				<< this->Array[i]->if_delect << endl;
			else if (this->Array[i]->department == 3 && t == 2 && this->Array[i]->if_delect)//卡号, 姓名, 性别, 部门, 每月工资(带有两位小数)
				ofs << this->Array[i]->department << ' '
				<< this->Array[i]->ID << ' '
				<< this->Array[i]->name << ' '
				<< this->Array[i]->sex << ' '
				<< this->Array[i]->depart << ' '
				<< this->Array[i]->salary << ' '
				<< this->Array[i]->if_delect << endl;
		}
	}
	ofs.close();
}
void manage::getinfo()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	ifs >> this->all_people_num;
	this->Array = new people * [all_people_num];
	for (int i = 0;i < this->all_people_num;i++)
	{
		int depart1;
		ifs >> depart1;
		switch (depart1)
		{
		case 1:
		{
			int ID;
			string name;
			int sex;
			string depart;
			int year;
			bool if_delect;
			ifs >> ID
				>> name
				>> sex
				>> depart
				>> year
				>> if_delect;
			this->Array[i] = new student(ID, name, sex, depart, year);
			this->Array[i]->if_delect = if_delect;
			this->Array[i]->department = depart1;
			break;
		}
		case 2:
		{
			int ID;
			string name;
			int sex;
			string depart;
			string subject;
			int year;
			bool if_delect;
			ifs >> ID
				>> name
				>> sex
				>> depart
				>> subject
				>> year
				>> if_delect;
			this->Array[i] = new teacher1(ID, name, sex, depart, subject, year);
			this->Array[i]->if_delect = if_delect;
			this->Array[i]->department = depart1;
			break;
		}
		case 3:
		{
			int ID;
			string name;
			int sex;
			string depart;
			double salary;
			bool if_delect;
			ifs >> ID
				>> name
				>> sex
				>> depart
				>> salary
				>> if_delect;
			this->Array[i] = new teacher2(ID, name, sex, depart, salary);
			this->Array[i]->if_delect = if_delect;
			this->Array[i]->department = depart1;
			break;
		}
		default:
			break;
		}
	}
	ifs.close();
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
			if (man != NULL) {
				man->if_delect = 1;
				newspace[this->all_people_num + i] = man;
			}
		}
		delete[] this->Array;
		this->Array = newspace;
		this->all_people_num = new_size;
	}
}
void manage::print_all_department()
{
	int choice;
	cout << "请输入人员职务：" << endl;
	printf("1.学生\n2.教师\n3.行政人员\n");
	cin >> choice;
	switch (choice)
	{
	case 1://学生卡号, 姓名, 性别, 学院, 入学年份
	{
		printf("卡号\t姓名\t性别\t学院\t入学年份\n");
		for (int i = 0;i < this->all_people_num;i++)
		{
			if (this->Array[i]->department == 1 && this->Array[i]->if_delect)
			{
				this->Array[i]->show_info();
			}
		}
		break;
	}
	case 2://教师卡号, 姓名, 性别, 学院, 教授科目, 教龄
	{
		printf("卡号\t姓名\t性别\t学院\t教授科目\t教龄\n");
		for (int i = 0;i < this->all_people_num;i++)
		{
			if (this->Array[i]->department == 2 && this->Array[i]->if_delect)
			{
				this->Array[i]->show_info();
			}
		}
		break;
	}
	case 3://卡号, 姓名, 性别, 部门, 每月工资(带有两位小数)
	{
		printf("卡号\t姓名\t性别\t部门\t每月工资\n");
		for (int i = 0;i < this->all_people_num;i++)
		{
			if (this->Array[i]->department == 3 && this->Array[i]->if_delect)
			{
				this->Array[i]->show_info();
			}
		}
		break;
	}
	default:
		cout << "输入错误！" << endl;
		break;
	}
}
void manage::print_all_depart()
{
	string search_depart;
	cout << "请输入要查询的学院：";
	cin >> search_depart;
	int t1 = 1, t2 = 1;
	for (int i = 0;i < this->all_people_num;i++)
	{
		if (this->Array[i]->depart == search_depart&&this->Array[i]->if_delect)
		{
			if (this->Array[i]->department == 1)
			{
				if (t1) {
					cout << "学生：" << endl;
					printf("卡号\t姓名\t性别\t学院\t入学年份\n");
					t1--;
				}
				this->Array[i]->show_info();
			}
			else
			{
				if (t2) {
					cout << "教师：" << endl;
					printf("卡号\t姓名\t性别\t学院\t教授科目\t教龄\n");
					t2--;
				}
				this->Array[i]->show_info();
			}
		}
	}
}
void manage::sreach()
{
	int flag = 1;
	int sreach_way;
	cout << "请输入查找方式：" << endl;
	cout << "1.按卡号查找" << endl << "2.按姓名查找" << endl;
	cin >> sreach_way;
	if (sreach_way == 1)
	{
		int sreach_id;
		cout << "请输入你要查询的人员卡号：";
		cin >> sreach_id;
		for (int i = 0;i < this->all_people_num;i++)
		{
			if (sreach_id == this->Array[i]->ID && this->Array[i]->if_delect)
			{
				flag = 0;
				switch (this->Array[i]->department)
				{
				case 1:
				{
					printf_s("卡号\t姓名\t性别\t学院\t入学年份\n");
					this->Array[i]->show_info();
					break;
				}
				case 2:
				{
					printf_s("卡号\t姓名\t性别\t学院\t教授科目\t教龄\n");
					this->Array[i]->show_info();
					break;
				}
				case 3:
				{
					printf_s("卡号\t姓名\t性别\t部门\t每月工资\n");
					this->Array[i]->show_info();
					break;
				}
				default:
					break;
				}
			}
		}
		if (flag) cout << "未找到此人！" << endl;
	}
	else if (sreach_way == 2)
	{
		string sreach_name;
		cout << "请输入你要查询的人员姓名：";
		cin >> sreach_name;
		for (int i = 0;i < this->all_people_num;i++)
		{
			if (sreach_name == this->Array[i]->name && this->Array[i]->if_delect)
			{
				flag = 0;
				switch (this->Array[i]->department)
				{
				case 1:
				{
					printf("卡号\t姓名\t性别\t学院\t入学年份\n");
					this->Array[i]->show_info();
					break;
				}
				case 2:
				{
					printf("卡号\t姓名\t性别\t学院\t教授科目\t教龄\n");
					this->Array[i]->show_info();
					break;
				}
				case 3:
				{
					printf("卡号\t姓名\t性别\t部门\t每月工资\n");
					this->Array[i]->show_info();
					break;
				}
				default:
					break;
				}
			}
		}
		if (flag) cout << "未找到此人！" << endl;
	}
}
void manage::salary_change()
{
	double salary_cg = 0;
	cout << "请输入对工资的整体调整：" << endl;
	cin >> salary_cg;
	for (int i = 0;i < this->all_people_num;i++)
		if (this->Array[i]->department == 3) this->Array[i]->salary += salary_cg;
	printf("此次对工资的调整为%.2lf￥\n", salary_cg);
}
bool manage::check(int ID, int t, people** mid)
{
	for (int i = 0;i < this->all_people_num + t;i++)
	{
		if (ID == mid[i]->ID && this->Array[i]->if_delect) return 1;
	}
	return 0;
}
void manage::delet()
{
	int delet_id;
	int flag = 1;
	cout << "请输入要删除的人员卡号：";
	cin >> delet_id;
	for (int i = 0;i < this->all_people_num;i++)
	{
		if (delet_id == this->Array[i]->ID)
		{
			int delect_confirm;
			flag = 0;
			cout << "要删除的人员信息如下："<<endl;
			printf("卡号\t姓名\t性别\t学院\t入学年份\n");
			this->Array[i]->show_info();
			cout << "确定删除该人员？" << endl;
			cout << "1.确定" << endl << "2.取消" << endl;
			cin >> delect_confirm;
			if (delect_confirm == 2) {
				cout << "已取消操作！" << endl;
				return;
			}
			cout << "已删除该人员！" << endl;
			this->Array[i]->if_delect = 0;
			all_people_num_change--;
		}
	}
	if (flag) cout << "未找到该人员！" << endl;
}
manage::~manage()
{
	if (this->Array != NULL)
	{
		delete[] this->Array;
		this->Array = NULL;
	}
} 