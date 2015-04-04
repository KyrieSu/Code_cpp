#include<iostream>
#include<string>
#include<map>
using namespace std ;



int main(){
	map<string, int> mp ;
	mp["one"] = 1 ;
	mp["two"] = 2 ;
	map<string, int>::iterator it = mp.begin() ;
	cout << it->first << endl ;
}
