#include <iostream>
#include <cstdlib>
#include "Point.h"
using namespace std;


Point::Point(){
	my_x = my_y = my_z = 0;
}

Point::Point(int x, int y, int z){
	my_x = x;
	my_y = y;
	my_z = z;
}

Point Point::operator++(){
	this->my_x++;
	this->my_y++;
	this->my_z++;
	return *this;
}

Point Point::operator+(Point addto){
	Point num;
	num.my_x = this->my_x + addto.my_x;
	num.my_y = this->my_y + addto.my_y;
	num.my_z = this->my_z + addto.my_z;
	return num;
}

Point Point::operator-(Point subto){
	Point num;
	num.my_x = this->my_x - subto.my_x;
	num.my_y = this->my_y - subto.my_y;
	num.my_z = this->my_z - subto.my_z;
	return num;
}

void Point::print(){
	printf_s("(%d,%d,%d)", this->my_x, this->my_y, this->my_z);
}
