#include"student.h"
student::student(int ID, string name, int sex, string depart, int year)
{
	this->ID = ID;
	this->name = name;
	this->sex = sex;
	this->depart = depart;
	this->year = year;
}
void student::show_info()
{
	cout << this->ID << '\t' << this->name << '\t';
	if (this->sex == 1) printf("ÄÐ\t");
	else printf("Å®\t");
	cout << this->depart << '\t' << this->year << endl;
}
string student::get_apartment_info()
{
	return "Ñ§Éú";
}