#include<iostream>
using namespace std ;

class Num{
	public:
		Num(int val){
			value = val ;
		}

		void print(){
			cout << value << endl ;
		}

		friend Num operator+(Num, Num) ;

	private:
		int value ;
} ;


int main(){
	Num a = 10 ;
	Num b = 20 ;

	Num c = a + b ;
	c.print() ;
}

Num operator+(Num in1, Num in2){
	return Num(in1.value + in2.value) ;
}


/********** Member Function **********/



/* Encapsulation concept */
