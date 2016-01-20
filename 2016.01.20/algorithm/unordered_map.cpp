#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
	unordered_map<char, int> m;
	m['a'] = 1;
	m['b'] = 2;
	m['c'] = 3;
	m['d'] = 4;

	cout << m.find('a')->first << endl;
}
