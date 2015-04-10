#include<iostream>
#include<string>
#include<sstream>
using namespace std ;

int main(){
	string input ;
	while(getline(cin, input)){  // input but not cut
		cout << input << endl ;
	}
}

