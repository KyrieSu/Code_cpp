#include<iostream>
using namespace std ;

class Num{
	public:
		Num(int val) ;			/* initialize */
		int getVal() ;			/* get value  */
		void setVal(int val) ;	/* set value  */

		Num operator+(Num in) ; /* operator + */
		Num operator*(Num in) ; /* operator * */
	private:
		int value ;
} ;

int main(){
	Num num1(60) ;
	Num num2(70) ;

	Num num3 = num1 + num2 ;


	cout << num1.getVal() << endl ;
	cout << num2.getVal() << endl ;
	cout << num3.getVal() << endl ;
}



Num::Num(int val){
	value = val ;
}

int Num::getVal(){
	return value ;
}

void Num::setVal(int val){
	value = val ;
}

Num Num::operator+(Num in){
    int temp = this->value + in.value ;
    Num result(temp) ;
    return result ;
}

Num Num::operator*(Num in){
    return Num(this->value + in.value) ;
}



