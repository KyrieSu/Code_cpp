#include<iostream>
using namespace std ;

class Object{
	public:
        static int num1, num2 ;
        Object() ;
        ~Object() ;
} ;


void hello(){
    Object *test = new Object ;
}

int main(){
	hello() ;
}





int Object::num1 = 1 ;
int Object::num2 = 1 ;

Object::Object(){
    cout << "OH YA" << num1 << endl ;
    num1++ ;
}

Object::~Object(){
    cout << "OH NO" << num2 << endl ;
    num2++ ;
}

