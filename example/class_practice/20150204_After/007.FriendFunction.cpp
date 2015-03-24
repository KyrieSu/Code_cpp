#include<iostream>
using namespace std ;

class Num2 ;

class Num1{
	public:
		Num1(int value){
			m_value = value ;
		}
		int getVal(){
			return m_value ;
		}
		friend int gcd(Num1, Num2) ;
	private:
		int m_value ;
} ;

class Num2{
	public:
		Num2(int value){
			m_value = value ;
		}
		int getVal(){
			return m_value ;
		}
		friend int gcd(Num1, Num2) ;
	private:
		int m_value ;
} ;

int gcd(Num1 a, Num2 b){
	int A = a.m_value ;
	int B = b.m_value ;
	return A ? gcd(B % A, A) : B ;
}

int main(){
	Num1 a = 6 ;
	Num2 b = 10 ;
	cout << gcd(a, b) ;
}
