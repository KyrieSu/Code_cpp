#include<iostream>
#include<sstream>
#include<string>
using namespace std ;

int main(){
	// make a string stream and output 1500 to string stream
	stringstream ss1 ;
	ss1 << 30 * 50 ;

	// initialize string by string stream
	string s1 = ss1.str() ;
	cout << s1 << endl ;

	// erase first char
	s1.erase(s1.begin()) ;
	cout << s1 << endl ;
}
