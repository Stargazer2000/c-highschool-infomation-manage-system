#include"teacher2.h"
teacher2::teacher2(int ID, string name, int sex, string depart,double salary)
{
	this->ID = ID;
	this->name = name;
	this->sex = sex;
	this->depart = depart;
	this->salary = salary;
}
void teacher2::show_info()
{
	cout<<this->ID<<'\t'<< this->name<<'\t';
	if (this->sex == 1) printf("��\t");
	else printf("Ů\t");
	cout<<this->depart<<'\t'<< this->salary<<endl;
}
string teacher2::get_apartment_info()
{
	return "������Ա";
}