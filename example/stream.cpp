#include<iostream>
#include<sstream>
using namespace std ;

int main(){
	// normal cout
	cout << "Hello World" << endl ;

	// friend function of class ostream
	operator<<(cout, "Hello World\n") ;

	// make a ostream by cout
	ostream myout(cout.rdbuf()); 
	myout << "Hello World" << endl ;

	// use ostream like cout
	operator<<(myout, "Hello World\n") ;

	// make a string by stringstream, and output the string
	stringstream ss ;
	ss << "Hello World" << endl ;
	cout << ss.str() ;

	return 0 ;
}
