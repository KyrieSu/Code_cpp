#include<iostream>
#include<cstdlib>
#include"HugeNumber.h"
using namespace std;

HugeNumber::HugeNumber(){
}

HugeNumber::~HugeNumber(){
	delete [] data;
}

void HugeNumber::random(unsigned int subscript){
	data = new short[subscript];
	int random[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i < subscript; i++)
		this->data[i] = random[rand()%10];
}


void HugeNumber::add_function(HugeNumber beadd){
	int check = this->getdigit()>beadd.getdigit() ? this->getdigit() : beadd.getdigit();
	int carry = 0;
	//for (int i = 0; i < check; i++)
}

void HugeNumber::sub_function(HugeNumber besub){
	cout << endl;
}

void HugeNumber::print(){
	for (int i = 0; i < this->getdigit(); i++)
		cout << this->data[i];
}

int HugeNumber::getdigit() {
	return sizeof(data) / sizeof(short);
}
