#include<iostream>
#include"HugeNumber.h"
using namespace std;

int main(){
	cout << "Enter seed";
	unsigned int seed;
	cin >> seed;
	srand(seed);
	cout << "Enter the lengths of three huge integers:";
	unsigned int x, y, z;
	cin >> x >> y >> z;


	return 0;
}