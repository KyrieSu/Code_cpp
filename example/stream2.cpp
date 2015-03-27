#include<iostream>
using namespace std ;

/* use function to print array */
void printArray(int *array){
	for(int i=0 ; i<5 ; i++)
		cout << array[i] << " " ;
	cout << endl ;
}

/* use operator overloading to print array */
ostream& operator<<(ostream& out, int *array){
	for(int i=0 ; i<5 ; i++)
		out << array[i] << " " ;
	return out ;
}

int main(){
	int array[5] = {1, 2, 3, 4, 5} ;

	printArray(array) ;
	cout << array << endl ;

}
