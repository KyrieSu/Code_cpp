#include<iostream>
#include<string>
using namespace std ;

int main(){
	int a, b, c ;
	string g1, g2 ;
	while(cin >> a >> b >> c >> g1 >> g2){
		cout << a << endl << b << endl << c << endl << endl ;
		if(a-b < 0)	cout << "(negative)0" << endl ;
		else	cout << a-b << endl ;
		if(b-c < 0)	cout << "(negative)0" << endl ;
		else	cout << b-c << endl ;
		cout << endl ;
	}
}
