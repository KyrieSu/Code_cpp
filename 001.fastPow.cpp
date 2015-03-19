#include<iostream>
using namespace std ;
/* a^n mod modBase */

// O(log(n))
int fastPow(int a, int n, int mod){
	long long r = 1, base = a ;
	while(n){	// n != 0
		if(n & 1)	r = (r*base) % mod ;
		base = (base*base) % mod ;
		n >>= 1 ;
	}
	return (int)r ;
}

// O(n)
int normalPow(int a, int n, int mod){
	long long r = 1 ;
	while(n--)	r = (r*a) % mod ;
	return (int)r ;
}

int main(){
	cout << fastPow(34567, 1000000000, 3333331) << endl ;
	cout << fastPow(345678, 1000000000, 3333331) << endl ;
	cout << fastPow(3456789, 1000000000, 3333331) << endl ;
	cout << endl ;
	cout << normalPow(34567, 1000000000, 3333331) << endl ;
	cout << normalPow(345678, 1000000000, 3333331) << endl ;
	cout << normalPow(3456789, 1000000000, 3333331) << endl ;
}
