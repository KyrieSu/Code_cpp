#include<iostream>
#include<vector>
#include<string>
#include<sstream>	// stringstream
#include<cstdlib>	// atoi()
using namespace std ;

vector<int> input2poly(const string& input){
	stringstream ss(input) ;
	string tempStr ;		// for cutting the string
	vector<int> poly ;
	while(getline(ss, tempStr, ' ')){
		int value = atoi(tempStr.c_str()) ;  // convert to int
		poly.push_back(value) ;
	}
	return poly ;
}

void derivative(vector<int>& poly){
	poly.pop_back() ;	// delete the last
	for(int i=0 ; i<poly.size() ; i++)
		poly[i] *= (poly.size() - i) ;
}

int calculate(int x, const vector<int>& poly){
	int sum = 0 ;
	for(int i=0 ; i<poly.size() ; i++){
		sum *= x ;
		sum += poly[i] ;
	}
	return sum ;
}

int main(){
	int x ;
	string input ;
	while(cin >> x){
		cin.get() ;		// delete the "\n"
		getline(cin, input) ;	// string input

		vector<int> poly = input2poly(input) ; // turn string to vector<int>
		derivative(poly) ;		// derivative
		cout << calculate(x, poly) << endl ;  // calculate answer
	}
}
