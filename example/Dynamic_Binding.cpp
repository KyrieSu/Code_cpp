#include<iostream>
#include<cstdlib>
using namespace std;

class Traffic{
	protected:
		static int mile;
	public:
		 virtual void Speedup()=0; // pure virtual function
};

int Traffic::mile=0;

class Car:public Traffic{
	public:
		void Speedup(){
			mile+=2;
			cout<<"Drive car to "<<mile<<endl;
		}
};

class Airplane:public Traffic{
	public:
		void Speedup(){
			mile+=15;
			cout<<"Drive Jet to "<<mile<<endl;
		}
};




int main(){
	Traffic *ptr;
	Car March;
	Airplane Jet;
	
	int keyin;
	while(true){
		cout<<"1. Drive Car"<<endl;
		cout<<"2. Drive Jet"<<endl;
		cout<<"3. Exit"<<endl;
		cin>>keyin;
		switch(keyin){
			case 1: ptr=&March; break;
			case 2: ptr=&Jet; break;
			case 3: exit(0);
		}
		ptr->Speedup();
		cout<<endl;
	}
	
	
	return 0;
}
