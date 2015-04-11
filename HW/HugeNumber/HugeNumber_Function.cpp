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
	for (int i = 0; i < subscript-1; i++)
		this->data[i] = rand() % 10;
	data[subscript - 1] = rand() % 9 + 1;
	my_digit = subscript;
}


void HugeNumber::add_function(HugeNumber addin){
	this->my_digit = this->my_digit > addin.my_digit ? this->my_digit : addin.my_digit;
	int carry = 0;
	for (int i = 0; i < this->my_digit; i++){
		int sum = this->data[i] + addin.data[i] + carry;
		this->data[i] = sum % 10;
		carry = sum / 10;
	}
	this->data[this->my_digit] = carry;
	if(this->data[my_digit])
		my_digit++;
}

void HugeNumber::sub_function(HugeNumber subto){
	check=(my_digit>=subto.my_digit);
	if(!check) return;
	for(int i=0;i<my_digit;i++){
		data[i]-=subto.data[i];
		if(data[i]<0){
			data[i+1]--;
			data[i]+=10;
		}
	}
	if(data[my_digit]<0)
		check=false;
	if(!check)
		return;
	
	while(data[my_digit-1]==0&&my_digit!=1)
		my_digit--;	
}


void HugeNumber::print(){
	if (!this->check){
		cout << "(negative)0" << endl;
		return;
	}
	for (int i = my_digit - 1; i >= 0; i--) /* First in Last out */
		cout << data[i];
	cout << endl;
}
