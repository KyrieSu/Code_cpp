#include<iostream>
using namespace std ;

class MyChar{
	public:
		MyChar(char chIn){
			ch = new char ;
			*ch = chIn ;
		}

		MyChar(const MyChar& in){
            return MyChar(*in.ch) ;
		}

		void print(){
			cout << *ch << endl ;
		}

		void set(char chIn){
			*ch = chIn ;
		}



	private:
		char *ch ;

} ;

int main(){
	MyChar str1('5') ;
	MyChar str2 = str1 ;
	str1.set('3') ;

	str1.print() ;
	str2.print() ;

	return 0 ;
}
