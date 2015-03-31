#include<iostream>
#include<cstdlib>
#include"HugeNumber.h"
using namespace std;

HugeNumber::HugeNumber(){
	data[50] = { 0 };
}

void HugeNumber::random(unsigned int digit){
	for (int i = 0; i < digit; i++){
		this->data[i] = rand() % 10;
	}
}


void HugeNumber::add_function(HugeNumber beadd){
	HugeNumber total;
	char carry = '0';
	for (int i = 0; i < 50; i++){
		int sum = (int)this->data[i] + beadd.data[i]  + carry;
		total.data[i] = (char)sum % 10;
		carry = (char)sum / 10;
	}
}

void HugeNumber::sub_function(HugeNumber besub){

}