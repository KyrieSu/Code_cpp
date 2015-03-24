#include<iostream>
#include<string>
#include<cstdio>
using namespace std ;

class Fraction{
	public:
		Fraction(int up, int down) ;		/* initialize				*/
		string toString() ;					/* "up/down"				*/
		int toInt() ;						/* interger part			*/
		int nearInt() ;						/* the nearest integer		*/
		double toDouble() ;					/* similar value in double	*/
		Fraction operator+(Fraction in) ;	/* add two fraction			*/
	private:
		static int gcd(int a, int b) ;
		int m_up ;
		int m_down ;
} ;


int main(){
	Fraction num1(10, 6) ;
	cout << num1.toString() << endl ;
	cout << num1.toInt() << endl ;
	cout << num1.nearInt() << endl ;
	cout << num1.toDouble() << endl ;

	Fraction num2 = Fraction(2, 3) + Fraction(3, 2) ;
	cout << num2.toString() << endl ;

	return 0 ;
}



/********** Member Function **********/

Fraction::Fraction(int up, int down){
	int k = gcd(up, down) ;
	m_up = up / k ;
	m_down = down / k ;
}

string Fraction::toString(){
	char temp[100] ;
	sprintf(temp, "%d/%d", m_up, m_down) ;
	return string(temp) ;
}

int Fraction::toInt(){
	return m_up / m_down ;
}

int Fraction::nearInt(){
	return int(toDouble() + 0.5) ;
}

double Fraction::toDouble(){
	return double(m_up)/m_down ;
}

int Fraction::gcd(int a, int b){
	return a ? gcd(b % a, a) : b ;
}

Fraction Fraction::operator+(Fraction in){
	int down = this->m_down * in.m_down ;
	int up = this->m_up * in.m_down + this->m_down * in.m_up ;
	return Fraction(up, down) ;
}

/********** Member Function **********/
