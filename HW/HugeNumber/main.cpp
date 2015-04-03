#include<iostream>
#include"HugeNumber.h"
using namespace std;

int main(){
	cout << "Enter seed: ";
	unsigned int seed;
	cin >> seed;
	srand(seed);
	cout << "Enter the lengths of three huge integers:";
	unsigned int x, y, z;
	cin >> x >> y >> z;

	HugeNumber n1, n2, n3;
	n1.random(x);
	cout << "N1: "; n1.print(); cout << endl;
	n2.random(y);
	cout << "N2: "; n2.print(); cout << endl;
	n3.random(z);
	cout << "N3: "; n3.print(); cout << endl;

	system("PAUSE");
	return 0;
}