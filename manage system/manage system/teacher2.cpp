#include"teacher2.h"
teacher2::teacher2(int ID, string name, int sex, string depart, double salary)
{
	this->ID = ID;
	this->name = name;
	this->sex = sex;
	this->depart_teacher3 = depart;
	this->salary = salary;
}
void teacher2::show_info()
{
	cout <<left<<setw(8) <<this->ID << left<<setw(8) << this->name ;
	if (this->sex == 1) printf("男\t");
	else printf("女\t");
	cout <<left<<setw(8) <<this->depart_teacher3 ;
	printf("\t%.2lf\n", this->salary);
}
string teacher2::get_apartment_info()
{
	return "行政人员";
}