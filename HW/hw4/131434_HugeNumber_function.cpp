#include"1031434_HugeInterger.h"
#include<iostream>
using namespace std;

ostream& operator<<(ostream& output, HugeInterger& BigNumber){
	unsigned int size = BigNumber.data.getsize();
	if (size == 0) cout << "0";
	for (int i = size - 1; i >= 0; i--)
		output << BigNumber.data[i];
	return output;
}

HugeInterger::HugeInterger(HugeInterger& right){
	this->data = right.data;
}

HugeInterger::HugeInterger(size_t size){
	data.resize(size, 0);
}

HugeInterger HugeInterger::random(size_t size){
	HugeInterger tmp;
	for (int i = 0; i < size - 1; i++)
		tmp.data.push_back(rand() % 10);
	tmp.data.push_back(rand() % 9 + 1);
	return tmp;
}

HugeInterger HugeInterger::zero(){
	HugeInterger tmp;
	tmp.data.push_back(0);
	return tmp;
}

HugeInterger HugeInterger::operator=(const HugeInterger& right){
	this->data = right.data;
	return *this;
}

bool HugeInterger::operator==(const HugeInterger& right){
	return this->data == right.data;
}

bool HugeInterger::operator!= (const HugeInterger& right){
	return !(*this == right);
}

bool HugeInterger::operator> (const HugeInterger& right){
	int this_size = this->data.getsize();
	int right_size = right.data.getsize();
	if (this_size < right_size)
		return false;
	for (int i = this_size - 1; i >= 0;i--)
		if (this->data[i] < right.data[i])
			return false;
	return true;
}

bool HugeInterger::operator< (const HugeInterger& right){
	return !(*this>right) && !(*this == right);
}

HugeInterger HugeInterger::operator+(const HugeInterger& right){
	HugeInterger num;
	int size = *this > right ? this->data.getsize() : right.data.getsize();
	for(int i = 0; i < size; i++){
		num.data[i] += this->data[i] + right.data[i];
		if (num.data[i]>9){
			num.data[i + 1] += num.data[i] / 10;
			num.data[i] %= 10;
		}
	}
	return num;
}

HugeInterger HugeInterger::operator-(const HugeInterger& right){
	HugeInterger num;
	if (*this < right){
		num.data.push_back(0);
		return num;
	}
	for (int i = 0; i < this->data.getsize(); i++){
		num.data[i] += this->data[i] - right.data[i];
		if (num.data[i] < 0){
			num.data[i + 1]--;
			num.data[i] += 10;
		}
	}
	/* §PÂ_¦ì¼Æ */
	return num;
}

HugeInterger HugeInterger::operator*(const HugeInterger& right){
	HugeInterger num;
	int this_size = this->data.getsize();
	int right_size = right.data.getsize();
	if ((this_size == 1 && this->data[0] == 0) || (right_size == 1 && right.data[0] == 0))
		num.data.push_back(0);
	for (int i = 0; i <this_size; i++)
	for (int j = 0; j < right_size; j++)
		num.data[i + j] += this->data[i] * right.data[j];
	for (int i = 0; i < this_size + right_size; i++){
		num.data[i + 1] += num.data[i] / 10;
		num.data[i] %= 10;
	}
	return num;
}

HugeInterger HugeInterger::operator/(const HugeInterger& right){
	HugeInterger num;
	HugeInterger copy = *this;
	int i = 0;
	while (true){
		copy = copy - right;
		if (copy < right)
			break;
		i++;
	}
	do{
		num.data.push_back(i % 10);
		i /= 10;
	} while (i);
	return num;
}

HugeInterger HugeInterger::operator%(const HugeInterger& right){
	HugeInterger copy = *this;
	while (true){
		copy = copy - right;
		if (copy < right)
			break;
	}
	return copy;
}



