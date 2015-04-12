#include<iostream>
#include<cstdlib>
#include"HugeNumber.h"
using namespace std;


int main(){
	unsigned int seed;
	cout << "Enter seed :";
	cin >> seed;
	srand(seed);

	unsigned int length1, length2, length3;
	cin >> length1 >> length2 >> length3;

	HugeNumber n1, n2, n3;
	n1 = HugeNumber::random(length1,n1);
	cout << "N1: " << n1 << endl;
	n2 = HugeNumber::random(length2,n2);
	cout << "N2: " << n2 << endl;
	n3 = HugeNumber::random(length3,n3);
	cout << "N3: " << n3 << endl;
	HugeNumber n4 = HugeNumber::zero(n4);
	cout << "N4: " << n4 << endl;

	cout << "N1 + N3 = " << n1 + n3 << endl;
	cout << "N2 - N3 = " << n2 - n3 << endl;
	cout << "N1 * N4 = " << n1 * n4 << endl;
	cout << "N4 = N2 + N3 * N1 = " << (n4 = n2 + n3 * n1) << endl;

	cout << endl << "Let N2 = N1, then..." << endl;
	n1 = n2;
	if (n1 == n2)
		cout << "N1 is equal to N2" << endl;

	if (n1 > n3)
		cout << "N1 is larger than N3" << endl;

	if (n1 < n3)
		cout << "N1 is smaller than N3" << endl;

	cout << "N4 / N2 = " << n4 / n2 << endl;
	HugeNumber n5;
	cout << "N5 = N4 % N2 = " << (n5 = n4 % n2) << endl;

	cout << endl;
	cout << "N1: " << n1 << endl;
	cout << "N2: " << n2 << endl;
	cout << "N3: " << n3 << endl;
	cout << "N4: " << n4 << endl;




	return 0;
}