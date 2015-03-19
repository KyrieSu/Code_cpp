#include<iostream>
using namespace std;

class Box{
public:
	Box(){ mylength = myheight = mywidth = 0; cout << "Box constructor called"<<endl; }
	Box(int x, int y,int z){
		myheight = x;
		mylength = y;
		mywidth = z;
		cout << "Box constructor called" << endl;
	}
	int volume(){ return myheight*mylength*mywidth; }
	bool compare(Box becmp){
		return this->volume() > becmp.volume() ? true : false ;
	}
private:
	int mylength;
	int mywidth;
	int myheight;
};

int main(){
	Box first(19,11,5),second(17,10,8);
	cout << "Volume of first box = " << first.volume() << endl;
	cout << "Volume of second box = " << second.volume() << endl;
	if (first.compare(second))
		cout << "The firstbox is greater than the second box" << endl;
	else
		cout << "The firstbox is not greater than the second box" << endl;


	system("PAUSE");
	return 0;
}
