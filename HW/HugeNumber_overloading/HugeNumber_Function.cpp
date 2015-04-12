#include<iostream>
#include"HugeNumber.h"
#include<vector>
using namespace std;

HugeNumber::HugeNumber(){
	check = true;
	my_digit = 1;
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
	out << endl;

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
	for (int i = my_digit - 1; i >= 0;i--)
		if (this->data[i] < right.data[i])
			return false;
	return true;
}

bool HugeNumber::operator<(const HugeNumber &right){
	return ! ( (*this>right) && (*this==right) );
}

HugeNumber HugeNumber::operator+(const HugeNumber &addin){
	HugeNumber num;
	if (my_digit > addin.my_digit)
		num.my_digit = my_digit;
	else
		num.my_digit = addin.my_digit;

	for (int i = 0; i < num.my_digit; i++)
		num.data[i] = this->data[i] + addin.data[i];
	for (int i = 0; i < num.my_digit; i++){
		num.data[i + 1] += num.data[i]/10;
		num.data[i] %= 10;
	}
	if (num.data[num.my_digit])
		num.my_digit++;

	return num;	
}

HugeNumber HugeNumber::operator-(const HugeNumber &right){
	HugeNumber num;
	num.check = (this->my_digit >= right.my_digit);
	if (!num.check) return;
	for (int i = 0; i < num.my_digit; i++){
		num.data[i] = this->data[i] - right.data[i];
		if (num.data[i] < 0){
			num.data[i + 1]--;
			num.data[i] += 10;
		}
	}


	if (num.data[my_digit] < 0){
		check = false;
		return;
	}

	while (data[my_digit - 1] == 0 && my_digit != 1)
		my_digit--;

	return num;
}

HugeNumber HugeNumber::operator*(const HugeNumber &right){
	HugeNumber num;
	num.my_digit = this->my_digit + right.my_digit; //the max digit 
	for (int i = 0; i < this->my_digit; i++)
		for (int j = 0; j < right.my_digit; j++)
			num.data[i+j] += this->data[i] * right.data[j];
	for (int i = 0; i < num.my_digit; i++){
		num.data[i + 1] += num.data[i]/10;
		num.data[i] %= 10;		
	}
	while (!num.data[my_digit - 1])
		my_digit--;

	return num;
}

HugeNumber HugeNumber::operator/(const HugeNumber &right){
	HugeNumber num;
	if (right.my_digit == 1 && right.data[0] == 0)
		return;
	num.my_digit = this->my_digit - right.my_digit + 1;
	

	return num;
}