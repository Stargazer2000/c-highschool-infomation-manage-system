#include"student.h"
student::student(int ID, string name, int sex, int depart, int year)
{
	this->ID = ID;
	this->name = name;
	this->sex = sex;
	this->depart = depart;
	this->year = year;
}
void student::show_info()
{
	cout <<left<<setw(8)<< this->ID << left<<setw(8) << this->name ;
	if (this->sex == 1) printf("ÄÐ\t");
	else printf("Å®\t");
	cout << depart_name1[this->depart] << "\t" << this->year << endl;
}
string student::get_apartment_info()
{
	return "Ñ§Éú";
}