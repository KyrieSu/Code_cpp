#include<iostream>
#include<string>
#include"Stack.h"
using namespace std;

int main(){
	Stack<int> A(5);
	for (int i = 0; i < 5; i++)
		A.push(i + 1);
	cout << A << endl;
	int timer = A.length();
	for (int i = 0; i < timer; i++)
		A.pop();
	cout << "Now A is a empty stack : " << (A.empty() ? "Yes" : "NO") << endl;
	Stack<string> B;
	B.push("Tzu");
	B.push("Lin");
	B.push("Wang");
	cout << B << endl;

	system("PAUSE");
	return 0;
}