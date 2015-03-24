#include<iostream>
using namespace std ;

inline int Max(int num1,int num2){
	return num1 > num2 ? num1 : num2 ;
}

inline int Min(int num1, int num2) ;



int main(){
	std::cout << Max(3, 5) << "\n" ;
	std::cout << Min(3, 5) << "\n" ;
}





int Min(int num1, int num2){
	return num1 < num2 ? num1 : num2 ;
}

