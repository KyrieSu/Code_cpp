#include<iostream>
#include<cstdlib>
#include"HugeNumber.h"
#include<ctime>
using namespace std;

int main(){
	int x, y, z ;
	srand(time(0)) ;
	while(cin >> x >> y >> z){
		HugeNumber n1, n2, n3;
		n1.random(x);
		n1.print();

		n2.random(y);
		n2.print();

		n3.random(z);
		n3.print();
		cout << endl ;

		n1.sub_function(n2);
		n1.print();

		n2.sub_function(n3);
		n2.print();
		cout << endl ;
	}
	return 0 ;
}
