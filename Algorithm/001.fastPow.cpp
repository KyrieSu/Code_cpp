#include<iostream>
using namespace std ;
/* a^n mod modBase */

// O(n)
int normalPow(int a, int n, int mod){
	long long r = 1 ;
	while(n--)	r = (r*a) % mod ;
	return (int)r ;
}

// O(log(n))
int fastPow(int a, int n, int mod){	long long r = 1, base = a ;
	while(n){	// n != 0
		if(n & 1)	r = (r*base) % mod ;
		base = (base*base) % mod ;
		n >>= 1 ;
	}
	return (int)r ;
}

// O(log(n))
int fastPow2(int a, int n, int mod){   // a^n = (a^(n/2))^2 
	if(n == 1)	return a % mod ;
	long long temp = fastPow2(a, n/2, mod) % mod ;
	if(n%2 == 1)	return ((temp * temp) % mod) * a % mod ;
	else	return temp * temp % mod ;
}

int main(){
	cout << fastPow(34567, 2000000000, 3333331) << endl ;
	cout << fastPow(345678, 2000000000, 3333331) << endl ;
	cout << fastPow(3456789, 2000000000, 3333331) << endl ;
	cout << endl ;
	cout << fastPow2(34567, 2000000000, 3333331) << endl ;
	cout << fastPow2(345678, 2000000000, 3333331) << endl ;
	cout << fastPow2(3456789, 2000000000, 3333331) << endl ;
	cout << endl ;
	cout << normalPow(34567, 2000000000, 3333331) << endl ;
	cout << normalPow(345678, 2000000000, 3333331) << endl ;
	cout << normalPow(3456789, 2000000000, 3333331) << endl ;
}
