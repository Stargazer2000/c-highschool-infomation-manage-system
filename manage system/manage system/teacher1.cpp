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
	cout << this->ID << '\t' << this->name << '\t';
	if (this->sex == 1) printf("ÄÐ\t");
	else printf("Å®\t");
	cout << this->depart << '\t' << this->subject << '\t' << this->year << endl;
}
string teacher1::get_apartment_info()
{
	return "½ÌÊ¦";
}