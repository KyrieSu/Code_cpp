#include<iostream>
using namespace std ;

class Math{
	public:

		static int power(int a, int b){
			int result = 1 ;
			for(int i=0 ; i<b ; i++)
				result *= a ;
			return result ;
		}

	private:
	    Math(){}
} ;

int main(){
	cout << Math::power(5, 3) << endl ;
}


