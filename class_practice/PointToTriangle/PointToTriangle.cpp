#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
using namespace std ;

/*************** Class ***************/ 

class Point{
	public:
		Point(int x, int y) ;	// initialize
		string toString() ;		// "(x,y)"
		inline int getX() ;
		inline int getY() ;
	private:
		int m_x, m_y ;
} ;

class Vector{
	public:
		Vector() ;
		Vector(Point srt, Point end) ;	// initialize
		double length() ;				// length of vector
		string toString() ;				// "(x,y)"
		Vector operator+(Vector in) ;	
		Vector operator-(Vector in) ;	
		static int dot(Vector fst, Vector snd) ;
		static int cross(Vector fst, Vector snd) ;
	private:
		int vx, vy ;
} ;

class Triangle{
	public:
		Triangle(Vector fst, Vector snd) ;
		Triangle(Point fst, Point snd, Point thd) ;
		int lengthSum() ;
		double area() ;
		bool operator!() ;
	private:
		Vector m_fst, m_snd ;
} ;

/*************** Class ***************/ 





int main(){
	Point myPoint1(2, 0), myPoint2(5, 0), myPoint3(5, 4) ;
	cout << myPoint1.toString() << endl ;	// (2,0)

	Vector myVector1(myPoint1, myPoint2) ;
	Vector myVector2(myPoint1, myPoint3) ;
	cout << (myVector1 + myVector2).toString() << endl ;	// (6,4)
	cout << Vector::dot(myVector1, myVector2) << endl ;		// 9
	cout << Vector::cross(myVector1, myVector2) << endl ;	// 12

	Triangle myTriangle1(myPoint1, myPoint2, myPoint3) ;
	Triangle myTriangle2(myVector1, myVector2) ;
	cout << myTriangle1.lengthSum() << endl ; // 12
	cout << myTriangle1.area() << endl ; // 6
	cout << !myTriangle2 << endl ; // 1(True)

	return 0 ;
}





/********** Point Member Function **********/

Point::Point(int x, int y){
	m_x = x ;
	m_y = y ;
}

string Point::toString(){
	char tmp[100] ;
	sprintf(tmp, "(%d,%d)", m_x, m_y) ;
	return string(tmp) ;
}

int Point::getX(){
	return m_x ;
}

int Point::getY(){
	return m_y ;
}

/********** Point Member Function **********/

/********** Vector Member Function **********/

Vector::Vector(){
	vx = vy = 0 ;
}

Vector::Vector(Point srt, Point end){
	vx = end.getX() - srt.getX() ;
	vy = end.getY() - srt.getY() ;
}

double Vector::length(){
	return sqrt(vx * vx + vy * vy) ;
}

string Vector::toString(){
	char tmp[100] ;
	sprintf(tmp, "(%d,%d)", vx, vy) ;
	return string(tmp) ;
}

Vector Vector::operator+(Vector in){
	Point newStart(0, 0) ;
	Point newEnd(this->vx + in.vx, this->vy + in.vy) ;
	return Vector(newStart, newEnd) ;
}

Vector Vector::operator-(Vector in){
	Point newStart(0, 0) ;
	Point newEnd(this->vx - in.vx, this->vy - in.vy) ;
	return Vector(newStart, newEnd) ;
}

int Vector::dot(Vector fst, Vector snd){
	return (fst.vx * snd.vx + fst.vy * snd.vy) ;
}


int Vector::cross(Vector fst, Vector snd){
	return (fst.vx * snd.vy + fst.vy * snd.vx) ;
}

/********** Vector Member Function **********/

/********** Triangle Member Function **********/

Triangle::Triangle(Vector fst, Vector snd){
	m_fst = fst ;
	m_snd = snd ;
}

Triangle::Triangle(Point fst, Point snd, Point thd){
	m_fst = Vector(fst, snd) ;
	m_snd = Vector(fst, thd) ;
}

int Triangle::lengthSum(){
	Vector m_thd = m_fst - m_snd ;
	return m_fst.length() + m_snd.length() + m_thd.length() ;
}

double Triangle::area(){
	return Vector::cross(m_fst, m_snd) * 0.5 ;
}

bool Triangle::operator!(){
	Vector m_thd = m_fst - m_snd ;
	if(Vector::dot(m_fst, m_snd) == 0)
		return true ;
	if(Vector::dot(m_thd, m_snd) == 0)
		return true ;
	if(Vector::dot(m_fst, m_thd) == 0)
		return true ;
	return false ;
}

/********** Triangle Member Function **********/

