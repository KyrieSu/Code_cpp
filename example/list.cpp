#include<iostream>
#include<list>
using namespace std ;
// list is made by linkedlist in the memory

void printList(list<int>& lst){
	if(lst.empty()){
		cout << "empty" << endl ;
		return ;
	}
	list<int>::iterator it ;
	for(it=lst.begin() ; it!=lst.end() ; it++)
		cout << *it << " " ;
	cout << endl ;
}

int main(){
	list<int> lst1(4, 100) ;	// four ints with value 100
	list<int> lst2(4, 50) ;		// four ints with value 50

	printList(lst1) ;
	printList(lst2) ;

	cout << "==========" << endl ;

	lst1.splice(lst1.end(), lst2) ;		// splice lst2 at lst1.end()
	printList(lst1) ;
	printList(lst2) ;

	cout << "==========" << endl ;
	lst2.assign(4, 25) ;		// four ints with value 25
	printList(lst1) ;
	printList(lst2) ;

	cout << "==========" << endl ;
	lst1.splice(lst1.begin(), lst2) ;	// splice lst2 at lst1.begin()
	printList(lst1) ;
	printList(lst2) ;
}
