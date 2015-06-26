#include<iostream>
#include<algorithm>
using namespace std;

#define Maxsize 10
class Stack{
	friend ostream& operator<<(ostream&,const Stack& R);
public:
	Stack();
	Stack(const Stack&);
	void swap(const Stack&); //C++11
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
	for(int i=0;i<R.size();i++)
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

void Stack::swap(const Stack& R){
	int arr[R.size()];
	for(int i=0;i<R.size();i++)
		arr[i]=R.data[i];
	int len=R.length;
	for(int i=0;i<this->size();i++)
		R.data[i]=this->data[i];
	R.length=this->length;
	for(int i=0;i<R.size();i++)
		this->data[i]=arr[i];
	this->length=len;
}


int main(){
	Stack A;
	/* intital status */
	cout<<"Stack is empty ? : "<<(A.empty()?"Yes":"No")<<endl;
	cout<<"Size of Stack is : "<<A.size()<<endl;//0
	/* add some elements */
	for(int i=0;i<Maxsize;i++)
		A.push(i+1);
	cout<<endl;	
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
	Stack B(A);
	cout<<B;
	timer=B.size();
	for(int i=0;i<timer;i++)
		B.pop();
	for(int i=0;i<Maxsize;i++)
		B.push(Maxsize-i);
	cout<<B;
	cout<<"----Swap A B----"<<endl;
	A.swap(B);
	cout<<A<<B;
	
	return 0;
}
