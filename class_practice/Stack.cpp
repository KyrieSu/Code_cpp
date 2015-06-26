#include<iostream>
#include<string>
using namespace std;

#define Maxsize 10
template<class T>
class Stack{
	friend ostream& operator<<(ostream& output,const Stack<T>& R){
		for(int i=0;i<R.size();i++)
			output<<R.data[i]<<" ";
		output<<endl;
		return output;
	}
public:
	Stack(){
		length=-1;
	}
	Stack(const Stack<T>& R){
		this->length=R.length;
		for(int i=0;i<R.size();i++)
			this->data[i]=R.data[i];
	}
	//void swap(const Stack&); //C++11
	T top()const{
		return data[length];
	}
	int size()const{
		return (length+1);
	}
	bool empty()const{
		return (length==-1);
	}
	void pop(){
		if(empty()){
			cout<<"Stack can't be pop"<<endl;
		return;
		}
		length--;
	}
	void push(T x){
		if( this->size()==Maxsize ){
			cout<<"Stack will be overflow"<<endl;
		return;
		}
		data[++length]=x;
	}
private:
	T data[Maxsize];
	int length;
};

//template<class T>
/*ostream& operator<<(ostream& output,const Stack<T>& R){
	for(int i=0;i<R.size();i++)
		output<<R.data[i]<<" ";
	output<<endl;
	return output;
}*/

/* Stack Function */
/*template<class T>
Stack::Stack(){
	for(int i=0;i<Maxsize;i++)
		this->data[i]=0;
	length=-1;
}

template<class T>
Stack::Stack(const Stack<T>& R){
	this->length=R.length;
	for(int i=0;i<R.size();i++)
		this->data[i]=R.data[i];
}

template<class T>
int Stack::size()const{
	return (length+1);
}

template<class T>
bool Stack::empty()const{
	return (length==-1);
}

template<class T>
void Stack::pop(){
	if(empty()){
		cout<<"Stack can't be pop"<<endl;
		return;
	}
	length--;
}

template<class T>
void Stack::push(T x){
	if( this->size()==Maxsize ){
		cout<<"Stack will be overflow"<<endl;
		return;
	}
	data[++length]=x;
}

template<class T>
T Stack::top()const{
	return data[length];
}*/


int main(){
	Stack<int> A;
	/* intital status */
	cout<<"Stack is empty ? : "<<(A.empty()?"Yes":"No")<<endl;
	cout<<"Size of Stack is : "<<A.size()<<endl;//0
	/* add some elements */
	for(int i=0;i<Maxsize;i++)
		A.push(i+1);
	cout<<"Stack is empty ? : "<<(A.empty()?"Yes":"No")<<endl;
	cout<<"Size of Stack is : "<<A.size()<<endl;
	cout<<A;
	cout<<"-----Now add the 11th elements to test push-----"<<endl;
	A.push(11);
	int timer=A.size();
	for(int i=0;i<timer;i++){
		A.pop();
		cout<<A.top()<<" ";
	}
	cout<<endl;	
	cout<<"Stack is empty ? : "<<(A.empty()?"Yes":"No")<<endl;//Yes
	cout<<"Size of Stack is : "<<A.size()<<endl;//0
	cout<<"-----Now delete a element to test pop-----"<<endl;
	A.pop();
	cout<<"Stack is empty ? : "<<(A.empty()?"Yes":"No")<<endl;//Yes
	cout<<"Size of Stack is : "<<A.size()<<endl;//0
	
	for(int i=0;i<Maxsize;i++)
		A.push(i+1);
	cout<<A;
	Stack<int> B(A);
	cout<<B;
	timer=B.size();
	for(int i=0;i<timer;i++)
		B.pop();
	for(int i=0;i<Maxsize;i++)
		B.push(Maxsize-i);
	cout<<B;
	cout<<"----- String Stack -----"<<endl;
	Stack<string> C;
	for(int i=0;i<Maxsize;i++)
		C.push("Kyrie Irving");
	cout<<C;
	for(int i=0;i<5;i++)
		C.pop();
	cout<<C;
	
	return 0;
}
