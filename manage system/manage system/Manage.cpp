#include"Manage.h"
void manage::menu()
{
	cout << "------------------------------------------" << endl;
	cout << "|�����������                            |" << endl;
	cout << "|1.����µ���Ա                          |" << endl;
	cout << "|2.ɾ��һ����Ա                          |" << endl;
	cout << "|3.����ĳ����Ա                          |" << endl;
	cout << "|4.��ʾĳ�ض�ְλ������Ա                |" << endl;
	cout << "|5.��ʾĳһѧԺ������Ա                  |" << endl;
	cout << "|6.��������Ա���ʵ��������              |" << endl;
	cout << "|7.����һ���µ�ѧԺ                      |" << endl;
	cout << "|8.�˳�ϵͳ                              |" << endl;
	cout << "------------------------------------------" << endl;
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
	case 7:
		this->add_new_department();
		break;
	default:
	{
		cout << "ϵͳ���˳���" << endl;
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
	ofs << this->all_people_num + all_people_num_change << ' ' << this->department_num << endl;
	for (int i = 1;i <= department_num;i++) ofs << depart_name[i] << endl;
	for (int t = 0;t < 3;t++)
	{
		for (int i = 0;i < this->all_people_num;i++)
		{
			if (this->Array[i]->department == 1 && t == 0 && this->Array[i]->if_delect)//ѧ������, ����, �Ա�, ѧԺ, ��ѧ���
				ofs << this->Array[i]->department << ' '
				<< this->Array[i]->ID << ' '
				<< this->Array[i]->name << ' '
				<< this->Array[i]->sex << ' '
				<< this->Array[i]->depart << ' '
				<< this->Array[i]->year << ' '
				<< this->Array[i]->if_delect << endl;
			else if (this->Array[i]->department == 2 && t == 1 && this->Array[i]->if_delect)//��ʦ����, ����, �Ա�, ѧԺ, ���ڿ�Ŀ, ����
				ofs << this->Array[i]->department << ' '
				<< this->Array[i]->ID << ' '
				<< this->Array[i]->name << ' '
				<< this->Array[i]->sex << ' '
				<< this->Array[i]->depart << ' '
				<< this->Array[i]->subject << ' '
				<< this->Array[i]->year << ' '
				<< this->Array[i]->if_delect << endl;
			else if (this->Array[i]->department == 3 && t == 2 && this->Array[i]->if_delect)//����, ����, �Ա�, ����, ÿ�¹���(������λС��)
				ofs << this->Array[i]->department << ' '
				<< this->Array[i]->ID << ' '
				<< this->Array[i]->name << ' '
				<< this->Array[i]->sex << ' '
				<< this->Array[i]->depart_teacher3 << ' '
				<< this->Array[i]->salary << ' '
				<< this->Array[i]->if_delect << endl;
		}
	}
	ofs.close();
}
bool manage::check_department(string s_check)
{
	for (int i = 1;i <= this->department_num;i++)
		if (this->depart_name[i] == s_check)
			return 0;
	return 1;
}
void manage::getinfo()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	ifs >> this->all_people_num;
	ifs >> this->department_num;
	depart_name = new string[department_num + 1];
	this->Array = new people * [all_people_num];
	for (int i = 1;i <= this->department_num;i++)
		ifs >> depart_name[i];
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
			int depart;
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
			this->Array[i]->get_depart_name(depart_name);
			break;
		}
		case 2:
		{
			int ID;
			string name;
			int sex;
			int depart;
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
			this->Array[i]->get_depart_name(depart_name);
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
			this->Array[i]->get_depart_name(depart_name);
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
	cout << "��������ӵ���Ա�����" << endl;
	cout << "1.ѧ��" << endl << "2.��ʦ" << endl << "3.������Ա" << endl;
	int depart = 0;
	cin >> depart;
	cout << "��������ӵ���Ա��������";
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
			case 1://ѧ������, ����, �Ա�, ѧԺ, ��ѧ���
			{
				int ID;
				string name;
				int sex;
				int department;
				int year;
				printf("�����%d��ѧ�����ţ�\n", i + 1);
				while (1)
				{
					cin >> ID;
					if (check(ID, i, newspace)) {
						cout << "�����ظ������������룡" << endl;
					}
					else break;
				}
				printf("�����%d��ѧ��������\n", i + 1);
				cin >> name;
				printf("�����%d��ѧ���Ա�\n", i + 1);
				printf("1.����\n2.Ů��\n");
				cin >> sex;
				printf("�����%d��ѧ��ѧԺ��\n", i + 1);
				for (int i = 1;i <= department_num;i++) cout << i << '.' << depart_name[i] << endl;
				while (1)
				{
					cin >> department;
					if (department >= 1 && department <= department_num) break;
					else cout << "����������������룡" << endl;
				}
				printf("�����%d��ѧ����ѧ��ݣ�\n", i + 1);
				cin >> year;
				man = new student(ID, name, sex, department, year);
				man->department = depart;
				man->get_depart_name(this->depart_name);
				cout << "�ѳɹ���Ӹ���Ա����Ա��Ϣ���£�" << endl;
				printf("����\t����\t�Ա�\tѧԺ\t\t��ѧ���\n");
				man->show_info();
				break;
			}
			case 2://��ʦ����, ����, �Ա�, ѧԺ, ���ڿ�Ŀ, ����
			{
				int ID;
				string name;
				int sex;
				int department;
				string sub;
				int year;
				printf("�����%d����ʦ���ţ�\n", i + 1);
				while (1)
				{
					cin >> ID;
					if (check(ID, i, newspace)) {
						cout << "�����ظ������������룡" << endl;
					}
					else break;
				}
				printf("�����%d����ʦ������\n", i + 1);
				cin >> name;
				printf("�����%d����ʦ�Ա�\n", i + 1);
				printf("1.����\n2.Ů��\n");
				cin >> sex;
				printf("�����%d����ʦѧԺ��\n", i + 1);
				for (int i = 1;i <= department_num;i++) cout << i << '.' << depart_name[i] << endl;
				while (1)
				{
					cin >> department;
					if (department >= 1 && department <= department_num) break;
					else cout << "����������������룡" << endl;
				}
				printf("�����%d����ʦ���ڿ�Ŀ��\n", i + 1);
				cin >> sub;
				printf("�����%d����ʦ���䣺\n", i + 1);
				cin >> year;
				man = new teacher1(ID, name, sex, department, sub, year);
				man->department = depart;
				man->get_depart_name(this->depart_name);
				cout << "�ѳɹ���Ӹ���Ա����Ա��Ϣ���£�" << endl;
				printf("����\t����\t�Ա�\tѧԺ\t\t���ڿ�Ŀ\t����\n");
				man->show_info();
				break;
			}
			case 3://����, ����, �Ա�, ����, ÿ�¹���(������λС��)
			{
				int ID;
				string name;
				int sex;
				string department;
				double salary;
				printf("�����%d��������Ա���ţ�\n", i + 1);
				while (1)
				{
					cin >> ID;
					if (check(ID, i, newspace)) {
						cout << "�����ظ������������룡" << endl;
					}
					else break;
				}
				printf("�����%d��������Ա������\n", i + 1);
				cin >> name;
				printf("�����%d��������Ա�Ա�\n", i + 1);
				printf("1.����\n2.Ů��\n");
				cin >> sex;
				printf("�����%d��������Ա���ţ�\n", i + 1);
				cin >> department;
				printf("�����%d��������Ա���ʣ�\n", i + 1);
				cin >> salary;
				man = new teacher2(ID, name, sex, department, salary);
				man->department = depart;
				cout << "�ѳɹ���Ӹ���Ա����Ա��Ϣ���£�" << endl;
				printf("����\t����\t�Ա�\t����\t\tÿ�¹���\n");
				man->show_info();
				break;
			}
			default:
				cout << "�������" << endl;
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
void manage::add_new_department()
{
	this->department_num++;
	string* newspace = new string[department_num + 1];
	for (int i = 1;i <= department_num - 1;i++) newspace[i] = depart_name[i];
	cout << "������Ҫ�����ѧԺ�����ƣ�" << endl;
	while (1)
	{
		cin >> newspace[department_num];
		if (check_department(newspace[department_num])) break;
		cout << "��ѧԺ�Ѵ��ڣ����������룡" << endl;
	}
	cout << "�ѳɹ����" << newspace[department_num] << '!' << endl;
	delete[] depart_name;
	depart_name = newspace;
	for (int i = 0;i < all_people_num;i++) this->Array[i]->get_depart_name(depart_name);
}
void manage::print_all_department()
{
	int choice;
	cout << "��������Աְ��" << endl;
	printf("1.ѧ��\n2.��ʦ\n3.������Ա\n");
	cin >> choice;
	switch (choice)
	{
	case 1://ѧ������, ����, �Ա�, ѧԺ, ��ѧ���
	{
		printf("����\t����\t�Ա�\tѧԺ\t\t��ѧ���\n");
		for (int i = 0;i < this->all_people_num;i++)
		{
			if (this->Array[i]->department == 1 && this->Array[i]->if_delect)
			{
				this->Array[i]->show_info();
			}
		}
		break;
	}
	case 2://��ʦ����, ����, �Ա�, ѧԺ, ���ڿ�Ŀ, ����
	{
		printf("����\t����\t�Ա�\tѧԺ\t\t���ڿ�Ŀ\t����\n");
		for (int i = 0;i < this->all_people_num;i++)
		{
			if (this->Array[i]->department == 2 && this->Array[i]->if_delect)
			{
				this->Array[i]->show_info();
			}
		}
		break;
	}
	case 3://����, ����, �Ա�, ����, ÿ�¹���(������λС��)
	{
		printf("����\t����\t�Ա�\t����\t\tÿ�¹���\n");
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
		cout << "�������" << endl;
		break;
	}
}
void manage::print_all_depart()
{
	int search_depart;
	bool if_found = 1;
	cout << "������Ҫ��ѯ��ѧԺ��" << endl;
	for (int i = 1;i <= department_num;i++) cout << i << '.' << depart_name[i] << endl;
	while (1)
	{
		cin >> search_depart;
		if (search_depart >= 1 && search_depart <= department_num) break;
		cout << "����������������룡" << endl;
	}
	int t1 = 1, t2 = 1;
	for (int i = 0;i < this->all_people_num;i++)
	{
		if (this->Array[i]->depart == search_depart && this->Array[i]->if_delect)
		{
			if (this->Array[i]->department == 1)
			{
				if (t1) {
					if_found = 0;
					cout << "ѧ����" << endl;
					printf("����\t����\t�Ա�\tѧԺ\t\t��ѧ���\n");
					t1--;
				}
				this->Array[i]->show_info();
			}
			else
			{
				if (t2) {
					if_found = 0;
					cout << "��ʦ��" << endl;
					printf("����\t����\t�Ա�\tѧԺ\t\t���ڿ�Ŀ\t����\n");
					t2--;
				}
				this->Array[i]->show_info();
			}
		}
	}
	if (if_found) cout << depart_name[search_depart] << "û����Ա��" << endl;
}
void manage::sreach()
{
	int flag = 1;
	int sreach_way;
	cout << "��������ҷ�ʽ��" << endl;
	cout << "1.�����Ų���" << endl << "2.����������" << endl;
	cin >> sreach_way;
	if (sreach_way == 1)
	{
		int sreach_id;
		bool s = 1, t1 = 1, t2 = 1;
		cout << "��������Ҫ��ѯ����Ա���ţ�";
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
					if (s){
						cout << "ѧ����" << endl;
						s=0;
					}
					printf_s("����\t����\t�Ա�\tѧԺ\t\t��ѧ���\n");
					this->Array[i]->show_info();
					return;
				}
				case 2:
				{
					if (t1) {
						cout << "��ʦ��" << endl;
						t1 = 0;
					}
					printf_s("����\t����\t�Ա�\tѧԺ\t\t���ڿ�Ŀ\t����\n");
					this->Array[i]->show_info();
					return;
				}
				case 3:
				{
					if (t2) {
						cout << "������Ա��" << endl;
						t2 = 0;
					}
					printf_s("����\t����\t�Ա�\t����\tÿ�¹���\n");
					this->Array[i]->show_info();
					return;
				}
				default:
					break;
				}
			}
		}
		if (flag) cout << "δ�ҵ����ˣ�" << endl;
	}
	else if (sreach_way == 2)
	{
		string sreach_name;
		bool s = 1, t1 = 1, t2 = 1;
		cout << "��������Ҫ��ѯ����Ա������";
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
					if (s) {
						cout << "ѧ����" << endl;
						s = 0;
					}
					printf("����\t����\t�Ա�\tѧԺ\t\t��ѧ���\n");
					this->Array[i]->show_info();
					break;
				}
				case 2:
				{
					if (t1) {
						cout << "��ʦ��" << endl;
						t1 = 0;
					}
					printf("����\t����\t�Ա�\tѧԺ\t\t���ڿ�Ŀ\t����\n");
					this->Array[i]->show_info();
					break;
				}
				case 3:
				{
					if (t2) {
						cout << "������Ա��" << endl;
						t2 = 0;
					}
					printf("����\t����\t�Ա�\t����\tÿ�¹���\n");
					this->Array[i]->show_info();
					break;
				}
				default:
					break;
				}
			}
		}
		if (flag) cout << "δ�ҵ����ˣ�" << endl;
	}
}
void manage::salary_change()
{
	double salary_cg = 0;
	cout << "������Թ��ʵ����������" << endl;
	cin >> salary_cg;
	for (int i = 0;i < this->all_people_num;i++)
		if (this->Array[i]->department == 3) this->Array[i]->salary += salary_cg;
	if (salary_cg > 0) printf("�˴ζ�������Ա�����幤��������%.2lf��\n", salary_cg);
	else if (salary_cg == 0) cout << "û�ж�������Ա���ʽ��е�����" << endl;
	else printf("�˴ζ�������Ա�����幤�ʼ�����%.2lf��\n", -salary_cg);
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
	cout << "������Ҫɾ������Ա���ţ�";
	cin >> delet_id;
	for (int i = 0;i < this->all_people_num;i++)
	{
		if (delet_id == this->Array[i]->ID)
		{
			int delect_confirm;
			flag = 0;
			cout << "Ҫɾ������Ա��Ϣ���£�" << endl;
			printf("����\t����\t�Ա�\tѧԺ\t��ѧ���\n");
			this->Array[i]->show_info();
			cout << "ȷ��ɾ������Ա��" << endl;
			cout << "1.ȷ��" << endl << "2.ȡ��" << endl;
			cin >> delect_confirm;
			if (delect_confirm == 2) {
				cout << "��ȡ��������" << endl;
				return;
			}
			cout << "��ɾ������Ա��" << endl;
			this->Array[i]->if_delect = 0;
			all_people_num_change--;
		}
	}
	if (flag) cout << "δ�ҵ�����Ա��" << endl;
}
manage::~manage()
{
	if (this->Array != NULL)
	{
		delete[] this->Array;
		this->Array = NULL;
	}
}