#include<list>
#include<iostream>
#include<algorithm>
using namespace std ;

/*
void print1(const list<int>& lst){
	for(int i=0 ; i<lst.size() ; i++)
		cout << lst[i] << " " ;
	cout << endl ;
}
*/

void print2(list<int>& lst){
	list<int>::iterator it ; 
	for(it=lst.begin() ; it!=lst.end() ; it++)
		cout << *it << " " ;
	cout << endl ;
}

int main(){
	list<int> lst1(10, 100) ;
	for(int i=0 ; i<lst1.size() ; i++)
		lst1[i] = i*i % 10 ; 

	print2(lst1) ;
	list<int>::iterator it = find(lst1.begin(), lst1.end(), 5) ;
	lst1.erase(it) ;
	print2(lst1) ;




	return 0 ;
}
