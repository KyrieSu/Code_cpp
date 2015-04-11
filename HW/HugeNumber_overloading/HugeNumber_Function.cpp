#include<iostream>
#include"HugeNumber.h"
using namespace std;

HugeNumber::HugeNumber(){
	check = true;
	my_digit = 0;
	for (int i = 0; i < Max; i++)
		data[i] = 0;
}

ostream &operator<<(ostream &out, const HugeNumber &toput){
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

HugeNumber HugeNumber::operator=(const HugeNumber &equalin){
	this->my_digit = equalin.my_digit;
	for (int i = 0; i < my_digit; i++)
		data[i] = equalin.data[i];
	return *this;
}

bool HugeNumber::operator==(const HugeNumber &right){
	if (this->my_digit != right.my_digit)
		return false;
	for (int i = 0; i < my_digit; i++)
		if (data[i] != right.data[i])
			return false;
	return true;
}

bool HugeNumber::operator!=(const HugeNumber &right){
	return !(*this == right);
}

bool HugeNumber::operator>(const HugeNumber &right){
	if (this->my_digit < right.my_digit)
		return false;
	for (int i = my_digit - 1; i >= 0;i++)
		if (this->data[i] < right.data[i])
			return false;
	return true;
}

bool HugeNumber::operator<(const HugeNumber &right){
	return !(*this>right);
}




HugeNumber HugeNumber::operator+(const HugeNumber &addin){
	HugeNumber num;
	
}