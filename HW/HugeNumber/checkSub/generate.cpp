#include<iostream>
#include<ctime>
#include<cstdlib>
#define T 1000000
using namespace std ;

int main(){
	srand(time(0)) ;
	for(int i=0 ; i<T ; i++){
		int a = rand() % 9 + 1 ; // from 1 ~ 9
		int b = rand() % 9 + 1 ; // from 1 ~ 9
		int c = rand() % 9 + 1 ; // from 1 ~ 9
		cout << a << " " << b << " " << c << endl ;
	}
}
