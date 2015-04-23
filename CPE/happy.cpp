#include<iostream>
using namespace std;
/* https://leetcode.com/problems/happy-number/ */
/* reference by : http://en.wikipedia.org/wiki/Happy_number */
/* [2,6] is not happy number*/

bool happy(int num){
	while(num>6){
		int sum=0;
		while(num){
			sum+=(num%10)*(num%10);
			num/=10;
		}
	num=sum;
	}
	return num==1;
}


int main(){
	int number;
	cin>>number;
	if(happy(number))
		cout<<number<<" is a happy number"<<endl;
	else
		cout<<number<<" is not a happy number"<<endl;	
}
