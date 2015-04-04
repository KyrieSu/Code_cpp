#include<set>
#include<iostream>
using namespace std ;

void print(set<int>& st){
	set<int>::iterator it ;
	for(it=st.begin() ; it!=st.end() ; it++)
		cout << *it << " " ;
	cout << endl ;
}

int main(){
	set<int> st1 ;
	st1.insert(3) ;	
	st1.insert(4) ;	
	st1.insert(6) ;	
	st1.insert(7) ;	
	st1.insert(5) ;	
	st1.insert(6) ;	
	print(st1) ;
}
