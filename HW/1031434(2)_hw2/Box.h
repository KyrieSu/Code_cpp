#ifndef _1031434_Box_h
#define _1031434_Box_h
#include<iostream>
#include<string>
#include<cstring>

class Ball{
public:
	Ball();
	Ball(double,double,double,std::string);
	~Ball();
	std::string name();
	double volume();
	int compare(Ball);
private:
	double length;
	double width;
	double height;
	std::string myname;
};

#endif