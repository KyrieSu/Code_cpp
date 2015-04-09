#include<iostream>
#include"HugeNumber.h"
using namespace std;

HugeNumber::HugeNumber(){
	check = true;
	my_digit = 0;
	for (int i = 0; i < Max; i++)
		data[i] = 0;
}

ostream &operator<<(ostream out, const HugeNumber &toput){
	if (!toput.check){
		cout << "(negative)0" << endl;
		return;
	}
	for (int i = 0; i < my_digit; i++)
		out << data[i];
	return out;
}


void HugeNumber::random(unsigned int subscript){
	for (int i = 0; i < subscript - 1; i++)
		data[i] = rand() % 10;
	data[subscript - 1] = rand() % 9 + 1;
	my_digit = subscript;
}

HugeNumber HugeNumber::operator+(const HugeNumber &addin){
	HugeNumber num;
	this->my_digit = this->my_digit > addin.my_digit ? this->my_digit : addin.my_digit;
	int carry = 0;
	for (int i = 0; i < this->my_digit; i++){
		int sum = this->data[i] + addin.data[i] + carry;
		this->data[i] = sum % 10;
		carry = sum / 10;
	}
	this->data[this->my_digit] = carry;
	if (this->data[my_digit])
		my_digit++;
	/* Copy the result to num */
	num.my_digit = my_digit;
	for (int i = 0; i < my_digit; i++)
		num.data[i] = this->data[i];
	return num;
}