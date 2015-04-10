#include<vector>
#include<iostream>
#include<algorithm>
using namespace std ;

void print1(const vector<int>& vec){
	for(int i=0 ; i<vec.size() ; i++)
		cout << vec[i] << " " ;
	cout << endl ;
}

void print2(vector<int>& vec){
	vector<int>::iterator it ; 
	for(it=vec.begin() ; it!=vec.end() ; it++)
		cout << *it << " " ;
	cout << endl ;
}

int main(){
	vector<int> vec1(10) ;
	for(int i=0 ; i<vec1.size() ; i++)
		vec1[i] = i*i % 10 ; 

	print1(vec1) ;
	vector<int>::iterator it = find(vec1.begin(), vec1.end(), 5) ;
	vec1.erase(it) ;
	sort(vec1.begin(),vec1.end());
	print1(vec1) ;




	return 0 ;
}


