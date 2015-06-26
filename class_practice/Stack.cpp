#include<iostream>
using namespace std;

#define Maxsize 10
class Stack{
	friend ostream& operator<<(ostream&,const Stack& R);
public:
	Stack();
	Stack(const Stack&);
	//void swap(); C++11
	int top()const;
	int size()const;
	bool empty()const;
	void pop();
	void push(int);
private:
	int data[Maxsize];
	int length;
	int *ptr;		
};

ostream& operator<<(ostream& output,const Stack& R){
	for(int i=0;i<R.size();i++)
		output<<R.data[i]<<" ";
	output<<endl;
	return output;
}

/* Stack Function */
Stack::Stack(){
	for(int i=0;i<Maxsize;i++)
		this->data[i]=0;
	length=-1;
	ptr=data;
}

Stack::Stack(const Stack& R){
	this->length=R.length;
	for(int i=0;i<length;i++)
		this->data[i]=R.data[i];
	ptr=(data+length);
}

int Stack::size()const{
	return (length+1);
}

bool Stack::empty()const{
	return (length==-1);
}

void Stack::pop(){
	if(empty()){
		cout<<"Stack can't be pop"<<endl;
		return;
	}
	length--;
	ptr--;
}

void Stack::push(int x){
	if( ptr == (data + Maxsize) ){
		cout<<"Stack will be overload"<<endl;
		return;
	}
	data[++length]=x;
	ptr++;	
}

int Stack::top()const{
	return data[length];
}



int main(){
	Stack A;
	/* intital status */
	cout<<"Stack is empty ? : "<<(A.empty()?"Yes":"No")<<endl;
	cout<<"Size of Stack is : "<<A.size()<<endl;//0
	/* add some elements */
	for(int i=0;i<Maxsize;i++){
		A.push(i+1);
		cout<<A.top()<<" ";
	}
	cout<<endl;	
	cout<<"Stack is empty ? : "<<(A.empty()?"Yes":"No")<<endl;
	cout<<"Size of Stack is : "<<A.size()<<endl;
	cout<<A;
	cout<<"-----Now add the 11th elements to test push-----"<<endl;
	A.push(11);
	for(int i=0;i<A.size();i++) // ->BUGGG
		A.pop();
	cout<<"Stack is empty ? : "<<(A.empty()?"Yes":"No")<<endl;//Yes
	cout<<"Size of Stack is : "<<A.size()<<endl;//0
	cout<<"-----Now delete a element to test pop-----"<<endl;
	A.pop();
	cout<<"Stack is empty ? : "<<(A.empty()?"Yes":"No")<<endl;//Yes
	cout<<"Size of Stack is : "<<A.size()<<endl;//0
	
	return 0;
}
