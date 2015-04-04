#include<iostream>
#include<cstdlib>
#include"HugeNumber.h"
using namespace std;

HugeNumber::HugeNumber(){
	my_digit = 0;
	for (int i = 0; i < Max; i++)
		data[i] = 0;
	check = true;
}

void HugeNumber::random(unsigned int subscript){
	for (int i = 0; i < subscript-1; i++){
		this->data[i] = rand() % 10;
		this->my_digit++;
	}
	data[subscript - 1] = rand() % 9 + 1;
	my_digit++;
}


void HugeNumber::add_function(HugeNumber addin){
	int step = this->my_digit > addin.my_digit ? this->my_digit : addin.my_digit;
	int carry = 0;
	for (int i = 0; i < step; i++){
		int sum = this->data[i] + addin.data[i] + carry;
		this->data[i] = sum % 10;
		carry = sum / 10;
	}
	this->data[step] = carry;
	if (carry)
		my_digit++;
}

void HugeNumber::sub_function(HugeNumber subto){
	if (this->my_digit < subto.my_digit){
		this->check = false;
		return;
	}
	
}
void HugeNumber::print(){
	if (!this->check){
		cout << "(negative)0" << endl;
		return;
	}
	else
	for (int i = my_digit - 1; i >= 0; i--) /* Like the Stack -> Last-in-first-out */
		cout << data[i];
}