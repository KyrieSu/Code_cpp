#include<iostream>
using namespace std ;

void printArray(int *array, int n){
	for(int i=0 ; i<n ; i++)
		cout << array[i] << " " ;
	cout << endl ;
	delete array ;
}

void print(int num){
    cout << num << endl ;
}

int main(){
	int array1[10] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8} ;

	printArray(array1, 10) ;

	print(3) ;

    int *array2 = new int[5]{1, 2, 3, 4, 5} ;
	printArray(    array2      , 5) ;
}
