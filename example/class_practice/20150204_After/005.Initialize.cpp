#include<iostream>
using namespace std ;

class Num{
	public:
		Num(int val = 0){
			value = val ;
		}

		Num(int val1, int val2){
			value = max(val1, val2) ;
		}

		void print(){
			cout << value << endl ;
		}
	private:
		int value ;
} ;

int main(){
	Num a(5) ;
	a.print() ;		// 5

	Num d = 6 ;
	d.print() ;

	Num *b = new Num(10) ;
	b->print() ;	// 10

	Num *c = new Num(15, 10) ;
	c->print() ;	// 15

	return 0 ;
}
