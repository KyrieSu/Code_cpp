#include<iostream>
using namespace std ;

class Rectangle{
	public:
		Rectangle(int length = 0, int width = 0) ;
		int area() ;
	private:
		int m_length ;
		int m_width ;
} ;

int main(){
	Rectangle myRectangle1 ;
	Rectangle myRectangle2(10) ;
	Rectangle myRectangle3(10, 20) ;

	cout << myRectangle1.area() << endl ;
	cout << myRectangle2.area() << endl ;	// 10 * 10 = 100
	cout << myRectangle3.area() << endl ;	// 10 * 20 = 200

	return 0 ;
}


Rectangle::Rectangle(int length, int width){
	m_length = length ;
	m_width = width ;
}

int Rectangle::area(){
	return m_length * m_width ;
}

