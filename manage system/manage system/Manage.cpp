#include"Manage.h"
void manage::menu()
{
	cout << "��ӭʹ�ø�У��Ϣ����ϵͳ1.0�汾" << endl;
	cout << "1.����µ���Ա" << endl;
	cout << "2.ɾ��һ����Ա" << endl;
	cout << "3.����ĳ����Ա" << endl;
	cout << "4.��ʾĳѧԺ������Ա" << endl;
	cout << "5.�˳�ϵͳ" << endl;
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
			if (this->Array[i]->department == 1 && t == 0)//ѧ������, ����, �Ա�, ѧԺ, ��ѧ���
				ofs << this->Array[i]->ID << " "
				<< this->Array[i]->name << " "
				<< this->Array[i]->sex << " "
				<< this->Array[i]->depart << " "
				<< this->Array[i]->year << endl;
			else if (this->Array[i]->department == 2 && t == 1)//��ʦ����, ����, �Ա�, ѧԺ, ���ڿ�Ŀ, ����
				ofs << this->Array[i]->ID << " "
				<< this->Array[i]->name << " "
				<< this->Array[i]->sex << " "
				<< this->Array[i]->depart << " "
				<< this->Array[i]->subject << " "
				<< this->Array[i]->year << endl;
			else if (this->Array[i]->department == 3 && t == 2)//����, ����, �Ա�, ����, ÿ�¹���(������λС��)
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
				string department;
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
				cin >> department;
				printf("�����%d��ѧ����ѧ��ݣ�\n", i + 1);
				cin >> year;
				man = new student(ID, name, sex, department, year);
				man->department = depart;
				break;
			}
			case 2://��ʦ����, ����, �Ա�, ѧԺ, ���ڿ�Ŀ, ����
			{
				int ID;
				string name;
				int sex;
				string department;
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
				cin >> department;
				printf("�����%d����ʦ���ڿ�Ŀ��\n", i + 1);
				cin >> sub;
				printf("�����%d����ʦ���䣺\n", i + 1);
				cin >> year;
				man = new teacher1(ID, name, sex, department, sub, year);
				man->department = depart;
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
				break;
			}
			default:
				cout << "�������" << endl;
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
