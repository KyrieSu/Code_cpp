#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

ostream &operator<<(ostream &output,const Date &toput){
	string str;
	switch (toput.my_month){
		case 1: str = "January"; break;
		case 2: str = "February"; break;
		case 3: str = "March"; break;
		case 4: str = "April"; break;
		case 5: str = "May"; break;
		case 6: str = "June"; break;
		case 7: str = "July"; break;
		case 8: str = "August"; break;
		case 9: str = "September"; break;
		case 10: str = "October"; break;
		case 11: str = "November"; break;
		case 12: str = "December";
	}
	
	output << str << " " << toput.my_day << ", " << toput.my_year;

	return output;
}

const int Date::days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(){
	my_day = 1;
	my_month = 1;
	my_year = 1990;
}

bool Date::leapyear(int year){
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	else
		return false;
}

Date::Date(int x, int y, int z){ // month,day,year 
	setDate(x, y, z);
}

void Date::setDate(int x, int y, int z){
	my_month = (x >= 1 && x <= 12) ? x : 1;
	my_year = (z >= 1990 && z <= 2100) ? z : 1990;
	if (my_month == 2 && leapyear(z))
		my_day = (y >= 1 && y <= 29) ? y : 1;
	else
		my_day = (y >= 1 && y <= 28) ? y : 1;
}

bool Date::endofmonth(int day){
	if (my_month == 2 && leapyear(my_year))
		return day == 29;
	else
		return day == days[my_month - 1];
}

void Date::help(){
	if (!endofmonth(my_day))
		my_day++;
	else
		if (my_month < 12){
			my_month++;
			my_day = 1;
		}
		else{
			my_year++;
			my_month = 1;
			my_day = 1;
		}
}

Date Date::operator+=(int timer){
	for (int i = 0; i < timer; i++)
		help();

	return *this;
}

Date Date::operator++(int one){
	Date num = *this;
	help();

	return num;
}

Date Date::operator++(){
	help();

	return *this;
}