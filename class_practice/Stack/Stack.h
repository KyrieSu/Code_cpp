#include<iostream>
#include<cstdlib>

template<class T>
class Stack{
	friend std::ostream& operator<<(std::ostream& output, const Stack<T>& R){
		for (int i = 0; i < R.length(); i++)
			output << R.Pointer[i] << " ";
		return output;
	}
public:
	Stack(int len = 10){
		size = (len > 0 ? len : 10);
		top = -1;
		Pointer = new T[size];
	}
	~Stack(){
		delete[] Pointer;
	}
	void push(const T x){
		if (full()){
			cout << "Stack will be overflow" << endl;
			return;
		}
		Pointer[++top] = x;
	}
	void pop(){
		if (empty()){
			cout << "Stack is empty. Cannot be pop" << endl;
			return;
		}
		top--;
	}
	size_t length()const{
		return (top + 1);
	}
	bool empty()const{
		return (top == -1);
	}
	bool full()const{
		return ((top + 1) == size);
	}
private:
	T *Pointer;
	int size;
	int top;
};