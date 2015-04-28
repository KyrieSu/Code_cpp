#include<iostream>
#include"Point.h"
using namespace std;

int main(){
	Line line(1, 1, 10, 10);
	Rectangle rect(10, 10, 90, 50);
	Triangle triangle(2,0,0,10,4,18);
	Circle circle(0, 0, 6, 8);
	cout << "Line area = " << line.area() << endl;
	cout << "Rectangle area = " << rect.area() << endl;
	cout << "Triangle area = " << triangle.area() << endl;
	cout << "Circle area = " << circle.area() << endl;
	

	system("PAUSE");
	return 0;
}