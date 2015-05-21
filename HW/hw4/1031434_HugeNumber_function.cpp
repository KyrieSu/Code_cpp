#include"1031434_HugeInterger.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

ostream& operator<<(ostream& output, HugeInterger& BigNumber){
	unsigned int size = BigNumber.data.getsize();
	if (size == 0) cout << "0";
	for (int i = size - 1; i >= 0; i--)
		output << BigNumber.data[i];
	return output;
}

HugeInterger::HugeInterger(HugeInterger& right)//copy constructor
:data(right.data)
{	
}

HugeInterger::HugeInterger(size_t size){
	data.resize(size);
	for (int i = 0; i < size; i++)
		data[i] = 0;
}

HugeInterger HugeInterger::random(size_t size){
	HugeInterger ans(size);
	for (int i = 0; i < size - 1; i++)
		ans.data[i] = rand() % 10;
	ans.data[size - 1] = rand() % 9 + 1;
	return ans;
}

HugeInterger HugeInterger::zero(){
	HugeInterger ans(1);
	ans.data[0] = 0;
	//cout << ans.data[0] << "****" << endl;
	return ans;
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
	if (this_size > right_size)
		return true;
	for (int i = this_size - 1; i >= 0;i--)
		if (this->data[i] < right.data[i])
			return false;
	return true;
}

bool HugeInterger::operator< (const HugeInterger& right){
	return !(*this>right) && !(*this == right);
}

void HugeInterger::operator+(const HugeInterger& right){
	/*int left_size = this->data.getsize();
	int right_size = right.data.getsize();
	int size = 0;
	if (left_size >= right_size)
		size = left_size;
	else
		size = right_size;
	HugeInterger ans(size + 1); 
	//cout << ans << "********" << endl; -> I try to output ans -> It's OK!
	//       ^^^ size is OK! It output size 0~  
	//cout << *this << "this***" << endl; -> OK
	for (int i = 0; i < size; i++){
		//cout << "FUCKKKKKK" << endl; -> ok
		//cout << right.data[i] << "right***" << endl;-> BUG here ( can't read this element )
		//cout << this->data[i] << "this***" << endl; -> ^^^^^^ also like the top 		
		ans.data[i] += this->data[i] + right.data[i];
		//cout << ans.data[i] << "*****" << endl;
		if (ans.data[i]>9){
			ans.data[i + 1] += ans.data[i] / 10;
			ans.data[i] %= 10;			
		}
	}
	return ans;*/
	cout << "I give up" << endl;
}

void HugeInterger::operator-(const HugeInterger& right){
	/*int left_size = this->data.getsize();
	int right_size = right.data.getsize();
	int size = 0;
	if (left_size >= right_size)
		size = left_size;
	else
		size = right_size;
	HugeInterger ans(size + 1);
	for (int i = 0; i < size; i++){
		ans.data[i] += this->data[i] - right.data[i];
		if (ans.data[i] < 0){
			ans.data[i + 1]--;
			ans.data[i] += 10;
		}
	}
	return ans;*/
	cout << "I give up" << endl;
}

void HugeInterger::operator*(const HugeInterger& right){
	/*int left_size = this->data.getsize();
	int right_size = right.data.getsize();
	if ((left_size == 1 && this->data[0] == 0) || (right_size == 1 && right.data[0] == 0)){
		HugeInterger special(1);
		special.data[0] = 0;
		return special;
	}
	int size = left_size + right_size + 1;
	HugeInterger ans(size);
	for (int i = 0; i < left_size; i++)
		for (int j = 0; j < right_size; j++)
			ans.data[i + j] += this->data[i] * right.data[j];
	for (int i = 0; i < ans.data.getsize(); i++){
		ans.data[i + 1] += ans.data[i] / 10;
		ans.data[i] %= 10;
	}
	return ans;*/
	cout << "I give up" << endl;
}

void HugeInterger::operator/(const HugeInterger& right){
	/*int left_size = this->data.getsize();
	int right_size = right.data.getsize();
	int size = 0;
	if (left_size >= right_size)
		size = left_size - right_size;
	else
		size = right_size - left_size;
	HugeInterger copy = *this;
	HugeInterger ans(size);
	int i = 0;
	while (true){
		copy = copy - right;
		if (copy < right)
			break;
		i++;
	}
	int index = 0;
	do{
		ans.data[index] = i % 10;
		i /= 10;
		index++;
	} while (i);

	return ans;*/
	cout << "I give up" << endl;
}

void HugeInterger::operator%(const HugeInterger& right){
	/*HugeInterger copy = *this;
	while (true){
		copy = copy - right;
		if (copy < right)
			break;
	}
	return copy;*/
	cout << "I give up" << endl;
}



