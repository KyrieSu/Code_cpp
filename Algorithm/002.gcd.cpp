#include<iostream>
using namespace std;

int gcd(int a,int b){
	return a==0 ? b:gcd(b%a,a);
}

int main(){
	int x,y;
	cout<<"Please input two integer :";
	cin>>x>>y;
	cout<<gcd(x,y)<<endl;
	
	return 0;
}
