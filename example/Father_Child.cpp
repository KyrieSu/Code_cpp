#include<iostream>
using namespace std;

class mathA{ /* find the max*/
	public:
		int getMax(const int a,const int b){
			return a>b ? a : b ;
		}
};

class mathB{ /* set ABS */
	public:
		int setABS(const int a){
			return a>0? a: (-1*a);
		}
};

class mathC:public mathA,public mathB{ /* Find the max (mathA) , set ABS (mathB) , GetFactorial (mathC) */
	public:
		int GetFractorial(int a){
			return a==0? 1:(a*GetFractorial(a-1));
		}
	
};


int main(){
	mathC poly;
	cout<<"100,65\t"<<poly.getMax(100,65)<<endl;
	cout<<"-99\t"<<poly.setABS(-99)<<endl;
	cout<<"5!\t"<<poly.GetFractorial(5)<<endl;
	
	return 0;
}
