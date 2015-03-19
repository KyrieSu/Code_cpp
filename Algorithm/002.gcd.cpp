#include<iostream>
using namespace std;

int gcd(const int &a, const int &b){
	return a ? gcd(b%a, a) : b ;
}


int main(){
	int x,y;
	cout<<"Please input two integer :";
	cin>>x>>y;
	cout<<gcd(x,y)<<endl;
	
	return 0;
}
