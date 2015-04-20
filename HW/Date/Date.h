#ifndef Date_h
#define Date_h

#include<iostream>

class Date{
	friend std::ostream &operator<<(std::ostream&, const Date&);
public:	
	Date();
	Date(int, int, int);
	void setDate(int, int, int);
	Date operator+=(int);
	Date operator++(int);
	Date operator++();
private:
	static const int days[12];
	int my_day;
	int my_month;
	int my_year;
	bool leapyear(int);
	bool endofmonth(int);
	void help();
};

#endif