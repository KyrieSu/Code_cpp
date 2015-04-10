#include<iostream>
#include<map>
using namespace std ;

template<class T1, class T2>
ostream& operator<<(ostream& out, map<T1, T2>& inMap){
	typename map<T1, T2>::iterator it ;
	for(it=inMap.begin() ; it!=inMap.end() ; it++)
		out << (it->first) << "\t" << (it->second) << endl ;
	return out ;
}

int main(){
	map<string, int> myMap ;
	myMap["one"] = 1 ;
	myMap["two"] = 2 ;
	myMap["three"] = 3 ;
	myMap["four"] = 4 ;
	myMap["five"] = 5 ;
	cout << myMap["four"] << endl ;	// 4
	cout << myMap["six"] << endl ;	// undefined -> 0
	// now myMap["six"] = 0 
	cout << myMap ;

	cout << "===============" << endl ;

	myMap["six"] = 6;
	cout << myMap ;

	cout << myMap.count("two") << endl ;
	map<string, int>::iterator it2 = myMap.find("two") ;
<<<<<<< HEAD
	myMap.erase(it2);
=======
	myMap.erase(it2) ;
>>>>>>> d097911c4203ad7ec7ed40553f41bc8baef105f5
	cout << myMap ;

}
