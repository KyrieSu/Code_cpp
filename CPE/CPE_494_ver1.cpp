#include<iostream>
#include<string>	// string, getline()
#include<cctype>	// isalpha()
#include<sstream>	// stringstream
using namespace std ;

int main(){
	string input ;
	while(getline(cin, input)){
		stringstream f(input) ;
		string temp ;
		int n = 0 ;
		while(getline(f, temp, ' '))
			if(isalpha(temp[0]))
				n++ ;
		cout << n << endl ;
	}
}
