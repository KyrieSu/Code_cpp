#include<iostream>
using namespace std ;

template <class T1, class T2>
double& Max(T1 &num1, T2 &num2){
	return num1 > num2 ? num1 : num2 ;
}

int main(){
    double a = 5.2 , b=4 ;
    Max(a, b)++ ;
	cout << a ;
}




/*	maxv
	int&	*/
