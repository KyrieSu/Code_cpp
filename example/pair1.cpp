#include<iostream>
#include<vector>
#include<utility>  // pair
using namespace std ;


int main(){
	pair<int, int> test1(10, 20) ;
	cout << test1.first << " " << test1.second << endl ;

	pair<string, int> test2("hello", 50) ;
	cout << test2.first << " " << test2.second << endl ;

	pair<int, int> test3 ;
	test3 = pair<int, int>(10, 8) ;
	cout << test3.first << " " << test3.second << endl ;

	pair<char, double> test4 ;
	test4 = make_pair('a', 9.0) ;
	cout << test4.first << " " << test4.second << endl ;
}
