#include<iostream>
using namespace std;

class function{
public:
	void Fraction(int,int);  //分數分子與分母
	void dec();		// "x/y"之字串
	int toint()	    /* 無條件捨去後之整數 */  { return x/y; }
	int nearint();	//四捨五入後之整數
	double todouble()   {return (double)x/(double)y;}
	// function operator+(function in);
private:
	int x,y;  /* x->分子,y->分母 */
};

void function::Fraction(int up,int down)
{
	x=up;
	y=down;
}

void function::dec()
{
	int max= x>y? x:y ;
	for(int i=max;i>1;i--)
		if(x%i==0 && y%i ==0){
		x=x/i;
		y=y/i;
		}
	cout<<x<<"/"<<y<<endl;
}

int function::nearint()
{
	double test=(double)x/(double)y;
	test=test*10;
	if( (int)test%10>=5 )
		return ((int)test/10) +1;
	else
		return ((int)test/10);
}




int main()
{
	function num;
	num.Fraction(10,6);
	num.dec();
	cout<<num.toint()<<endl;
	cout<<num.nearint()<<endl;
	cout<<num.todouble()<<endl;



	return 0;
}
