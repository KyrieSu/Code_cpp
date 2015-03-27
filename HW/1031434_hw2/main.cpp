#include<iostream>
#include<cstring>
#include<string>
#include"Box.h"
using namespace std;

int main(){
	Ball firstBox(19.0, 11.0, 5.0, "FirstBox");
	Ball secondBox(17.0, 10.0, 8.0, "SecondBox");

	cout << "Volume of " << firstBox.name() << " = " << firstBox.volume() << endl;
	cout << "Volume of " << secondBox.name() << " = " << secondBox.volume() << endl;

	cout << firstBox.name()
		<< " is "
		<< (firstBox.compare(secondBox) > 0 ? "" : "not ")
		<< "greater than "
		<< secondBox.name()
		<< endl;
	system("PAUSE");
	return 0;
}