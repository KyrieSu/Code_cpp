#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std ;

vector<string> str2tok(const string& str, char delim){
	stringstream ss(str) ;
	string temp ;
	vector<string> token ;
	while(getline(ss, temp, delim))
		token.push_back(temp) ;
	return token ;
}

int main(){
	cout << "Enter 0 to quit" << endl ;
	string str ;
	while(getline(cin, str)){
		if(str == "0")
			break ;

		vector<string> token = str2tok(str, ' ') ;
		for(int i=0 ; i<token.size() ; i++)
			cout << token[i] << endl ;
		cout << endl ;
	}
}
