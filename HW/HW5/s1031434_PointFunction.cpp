#include"s1031434_Point.h"

/* Point Function */

Point::Point(int x, int y){
	my_X = x;
	my_Y = y;
}

/* Vector Function */

Vector::Vector(){
	Q.my_X = 0;
	Q.my_Y = 0;
}

Vector::Vector(Point& A, Point& B){
	Q.my_X = B.my_X - A.my_X;
	Q.my_Y = B.my_Y - A.my_Y;
}

Vector Vector::operator+(Vector& right){
	Point original(0, 0);
	Point newStart(this->my_X + right.my_X, this->my_Y + right.my_Y);
	return Vector(original, newStart);
}

Vector Vector::operator-(Vector& right){
	Point original(0, 0);
	Point newStart(this->my_X - right.my_X, this->my_Y - right.my_Y);
	return Vector(original, newStart);
}

double Vector::dot(Vector& left, Vector& right){
	return (left.my_X*right.my_X + left.my_Y*right.my_Y);
}

double Vector::cross(Vector& left, Vector& right){
	return (left.my_X*right.my_Y + left.my_Y*right.my_X);
}

