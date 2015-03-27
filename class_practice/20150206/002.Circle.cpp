#include<iostream>
using namespace std ;

class Circle{
	public:
	    static const double PI = 3.14 ;
		Circle(double r) ;	/* initial with r */
		Circle() ;          /* initialize */
		double area() ;		/* area of circle */
	private:
		double radius ;
};

int main(){
	Circle cir1(10) ;
	cout << cir1.area() << endl ;
}

/********** Circle Member Function **********/

Circle::Circle(double r){
	radius = r ;
}

Circle::Circle(){
    radius = 0 ;
}

double Circle::area(){
	return radius * radius * PI ;
}

/********** Circle Member Function **********/
