#include<iostream>
#include<string>
using namespace std ;

int main(){
	int T ;
	cin >> T ;
	while(T--){
		int sum = 0 ;
		string input ;
		cin >> input ;
		int array[input.size()] ;
		array[0] = (input[0] == 'O') ;
		for(int i=1 ; i<input.size() ; i++){
			if(input[i] == 'X')	array[i] = 0 ;
			else	array[i] = array[i-1] + 1 ;
		}
		for(int i=0 ; i<input.size() ; i++)
			sum += array[i] ;
		cout << sum << endl ;
	}
}
