#include<iostream>
#include<vector>
#include"HugeNumber.h"
using namespace std;

HugeNumber::HugeNumber(){
	check = true;
	my_digit = 1;
	for (int i = 0; i < Max; i++)
		data[i] = 0;
}

HugeNumber HugeNumber::zero(HugeNumber &right){
	right.data[0] = 0;
	right.my_digit = 1;
}

ostream &operator<<(ostream &output, const HugeNumber &toput){
	if (!toput.check){
		output << "(negative)";
		return output;
	}
	for (int i = 0; i < toput.my_digit; i++)
		output << toput.data[i];
	output << endl;

	return output;		
}

HugeNumber HugeNumber::random(unsigned int subscript,HugeNumber &me){
	for (int i = 0; i < subscript - 1; i++)
		me.data[i] = rand() % 10;
	me.data[subscript - 1] = rand() % 9 + 1;
	me.my_digit = subscript;
}

HugeNumber HugeNumber::operator=(const HugeNumber &equalin){
	this->my_digit = equalin.my_digit;
	this->check = equalin.check;
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
	return !(*this>right) && !(*this == right);
}

HugeNumber HugeNumber::operator+(const HugeNumber &addin){
	HugeNumber num;
	if (my_digit > addin.my_digit)
		num.my_digit = my_digit;
	else
		num.my_digit = addin.my_digit;

	for (int i = 0; i < num.my_digit; i++){
		num.data[i] += this->data[i] + addin.data[i];
		if (num.data[i]>9){
			num.data[i + 1] += num.data[i] / 10;
			num.data[i] %= 10;
		}
	}
	if (num.data[num.my_digit])
		num.my_digit++;

	return num;	
}

HugeNumber HugeNumber::operator-(const HugeNumber &right){
	HugeNumber num;
	num.check = (this->my_digit >= right.my_digit);
	if (!num.check){
		num.data[0] = 0;
		return num;
	}
	for (int i = 0; i < num.my_digit; i++){
		num.data[i] += this->data[i] - right.data[i];
		if (num.data[i] < 0){
			num.data[i + 1]--;
			num.data[i] += 10;
		}
	}

	while (num.data[num.my_digit - 1] == 0 && num.my_digit != 1)
		num.my_digit--;
	
	if (num.data[num.my_digit] < 0){
		num.check = false;
		return num;
	}

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

	if(!num.data[my_digit - 1])
		num.my_digit--;

	return num;
}

HugeNumber HugeNumber::helpdivison(int Q,int fill){  // this => todiv => right
	HugeNumber num;
	vector<short> vec(this->my_digit);
	for (int i = 0; i < this->my_digit; i++)
		vec[i] = this->data[i];
	while (fill--)
		vec.push_back(0);
	for (int i = 0; i < vec.size(); i++)
		num.data[i] = vec[i];
	num.my_digit = vec.size();
	for (int i = 0; i < num.my_digit; i++)
		num.data[i] *= Q;
	for (int i = 0; i < num.my_digit;i++)
		if (num.data[i]>9){
			num.data[i + 1] += num.data[i] % 10;
			num.data[i] /= 10;
		}
	if (num.data[my_digit])
		num.my_digit++;

	return num;
}



HugeNumber HugeNumber::operator/(const HugeNumber &right){
	HugeNumber num;
	num.my_digit = this->my_digit - right.my_digit;
	if (this->data[my_digit - 1] > right.data[my_digit - 1])
		num.my_digit++;

	HugeNumber todiv = right;
	HugeNumber copy = *this;
	for (int j = num.my_digit; j > 0;j--)
		for (int i = 0; i < 10;i++)
			if (todiv.helpdivison(i,j-1)>copy){
				copy = copy - todiv.helpdivison(i,j);
				num.data[num.my_digit - 1] = i - 1;
				break;
			}

	return num;
}

HugeNumber HugeNumber::operator%(const HugeNumber &right){
	HugeNumber num;
	num.my_digit = this->my_digit - right.my_digit;
	if (this->data[my_digit - 1] > right.data[my_digit - 1])
		num.my_digit++;

	HugeNumber todiv = right;
	HugeNumber copy = *this;
	for (int j = num.my_digit; j > 0; j--)
		for (int i = 0; i < 10; i++)
			if (todiv.helpdivison(i, j - 1)>copy){
				copy = copy - todiv.helpdivison(i, j);
				num.data[num.my_digit - 1] = i - 1;
				break;
			}
	num = copy;
	num.my_digit = right.my_digit;
	while (num.data[num.my_digit - 1] == 0 && num.data[num.my_digit - 2] == 0)
		num.my_digit--;
		
	return num;
}