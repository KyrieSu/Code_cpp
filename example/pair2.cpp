#include<iostream>
#include<vector>
#include<utility>  // pair
using namespace std ;

template<class T1, class T2>
void printPair(pair<T1, T2> val){
	cout << val.first << " " << val.second << endl ; 
}

int main(){
	pair<int, int> test1(10, 20) ;
	printPair(test1) ;

	pair<string, int> test2("hello", 50) ;
	printPair(test2) ;

	pair<int, int> test3 ;
	test3 = pair<int, int>(10, 8) ;
	printPair(test3) ;

	pair<char, double> test4 ;
	test4 = make_pair('a', 9.0) ;
	printPair(test4) ;
}
