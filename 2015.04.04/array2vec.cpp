#include<iostream>
#include<vector>
#include<list>
using namespace std ;

void printVec(vector<int>& vec){
	vector<int>::iterator it ; 
	for(it=vec.begin() ; it!=vec.end() ; it++)
		cout << *it << " " ;
	cout << endl ;
}

void printLst(list<int>& lst){
	list<int>::iterator it ; 
	for(it=lst.begin() ; it!=lst.end() ; it++)
		cout << *it << " " ;
	cout << endl ;
}

int main(){
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} ;
	vector<int> vec1(array, array+10) ;
	vector<int> vec2(vec1.begin(), vec1.end()) ;
	printVec(vec1) ;

	list<int> lst1(vec1.begin(), vec1.end()) ;
	printLst(lst1) ;
	
	return 0 ;
}
