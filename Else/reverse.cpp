#include<iostream>
#include<ctime>
#include<vector>
#include<algorithm>
using namespace std ;

void random(vector<int> &vec){
	for(int i=0 ; i<vec.size() ; i++)
		vec[i] = rand() % 100 ;
}

void print(vector<int> &vec){
	for(int i=0 ; i<vec.size() ; i++)
		cout << vec[i] << " " ;
	cout << endl ;
}

int main(){
	srand(time(0)) ;
	vector<int> vec1(10) ; 

	random(vec1) ;
	cout << "unsorted: " ;
	print(vec1) ;

	sort(vec1.begin(), vec1.end()) ;  /* <algorithm> */
	cout << "sorted: " ;
	print(vec1) ;

	vec1.insert(vec1.end(), 3, 99999) ; /* add 3 99999 at the end */
	vec1.insert(vec1.begin(), 3, 11111) ; /* add 3 11111 at the begin */
	vec1.insert(vec1.begin() + vec1.size()/2, 55555) ; /* add 55555 in the middle */
	print(vec1) ;

	vec1.clear() ;
	vec1.insert(vec1.begin(), 10, 100) ;
	print(vec1) ;

}




