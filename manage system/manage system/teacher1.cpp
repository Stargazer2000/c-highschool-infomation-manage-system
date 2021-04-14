#include"teacher1.h"
teacher1::teacher1(int ID, string name, int sex, string depart, string sub, int year)
{
	this->ID = ID;
	this->name = name;
	this->sex = sex;
	this->depart = depart;
	this->subject = sub;
	this->year = year;
}
void teacher1::show_info()
{
	cout <<left<<setw(8)<< this->ID <<left<<setw(8) << this->name ;
	if (this->sex == 1) printf("ÄÐ\t");
	else printf("Å®\t");
	cout <<left<<setw(16) <<this->depart << left<<setw(16) << this->subject << this->year << endl;
}
string teacher1::get_apartment_info()
{
	return "½ÌÊ¦";
}