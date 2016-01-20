#include<iostream>
#include<cassert>
#include<stack>
using namespace std;



int main(){
	stack<int> s;
	s.push(10);
	assert(s.size() >= 1);
	s.pop();
}
