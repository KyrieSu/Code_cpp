#include<iostream>
#include<cstdlib>
#include"HugeNumber.h"
using namespace std;

HugeNumber::HugeNumber(){
	my_digit = 1;
	data[100] = { 0 };	// ??
}

void HugeNumber::random(unsigned int subscript){	// ??
	int random[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i < subscript; i++){
		this->data[i] = random[rand() % 10];
		this->my_digit++;
	}
}


void HugeNumber::add_function(HugeNumber beadd){
	cout << endl;
}

void HugeNumber::sub_function(HugeNumber besub){
	cout << endl;
}

void HugeNumber::print(){
	for (int i = 0; i < my_digit; i++)
		cout << data[i];
}

