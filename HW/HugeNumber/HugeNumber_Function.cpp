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
	while (this->data[my_digit])
		my_digit++;
	
	/*
	if(my_digit < addin.my_digit)
		my_digit = addin.my_digit ;
	for(int i=0 ; i<my_digit ; i++)	// add all
		data[i] += addin.data[i] ;
	for(int i=0 ; i<my_digit ; i++){ // carry all
		data[i+1] += data[i] / 10 ;
		data[i] %= 10 ;
	}
	if(data[my_digit])	
		my_digit++ ;
	*/
}

void HugeNumber::sub_function(HugeNumber subto){
	if (this->my_digit < subto.my_digit){
		this->check = false;
		return;
	}
	for (int i = 0; i < this->my_digit; i++)
		this->data[i] -= subto.data[i];

	if (this->data[my_digit] < 0){ 
		check = false;
		return;
	}

	for (int i = 0; i < this->my_digit; i++)
		if (this->data[i] < 0){
			this->data[i + 1]--;
			this->data[i] += 10;
		}

	while (!this->data[my_digit - 1])
		my_digit--;
}


void HugeNumber::print(){
	if (!this->check){
		cout << "(negative)0" << endl;
		return;
	}
	else
		for (int i = my_digit - 1; i >= 0; i--) /* First in Last out */
			cout << data[i];
		cout << endl;
}
