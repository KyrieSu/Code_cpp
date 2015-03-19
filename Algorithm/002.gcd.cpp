#include<iostream>
using namespace std;

int gcd(int a,int b){
	return a==0 ? b:gcd(b%a,a);
}


int gcd2(int a,int b){
	return a ? gcd(b%a, a) : b ;
}


int main(){
	int x,y;
	cout<<"Please input two integer :";
	cin>>x>>y;
	cout<<gcd(x,y)<<endl;
	cout<<gcd2(x,y)<<endl;
	
	return 0;
}
