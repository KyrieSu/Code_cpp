#include"Point.h"
#include<cmath>
#define PI 3.1415

Point::Point(){
	x = 0;
	y = 0;
}

int Figure::area(){
	return 0;
}

Line::Line(int x1, int y1, int x2, int y2){
	A.x = x1;
	A.y = y1;
	B.x = x2;	
	B.y = y2;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2){
	A.x = x1;
	A.y = y1;
	B.x = x2;
	B.y = y2;
}

int Rectangle::area(){
	int length = abs(A.x - B.x);
	int hight = abs(A.y - B.y);

	return length*hight;
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3){
	A.x = x1;	A.y = y1;
	B.x = x2;	B.y = y2;
	C.x = x3;	C.y = y3;
}

double Triangle::area(){
	int ab = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
	int ac = sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2));
	int bc = sqrt(pow(B.x - C.x, 2) + pow(B.y - C.y, 2));
	int S = (ab + bc + ac) / 2;

	return sqrt(S*(S - ab)*(S - ac)*(S - bc));
}

Circle::Circle(int x1, int y1, int x2, int y2){
	A.x = x1;	A.y = y1;
	B.x = x2;	B.y = y2;
}

double Circle::area(){
	double radious = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
	
	return radious*radious*PI;
}




