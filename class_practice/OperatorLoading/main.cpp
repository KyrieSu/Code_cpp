#include <iostream>
#include "Point.h"
#include <cstdlib>
using namespace std;


int main(){
	Point p1(50, 40, 60);
	Point p2(30, 20, 10);
	Point p3 = p1 + p2;
	p3.print();
	cout << endl;
	p3 = p1 - p2;
	p3.print();
	p3++;
	cout << endl;
	p3.print();
	cout << endl;


	system("PAUSE");
	return 0;
}
