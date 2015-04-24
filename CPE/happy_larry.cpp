#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int Happy[] = {1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97, 100} ;

bool ishappy(int x){
	while(x > 100){
		int sum = 0 ;
		while(x){
			sum += (x%10) * (x%10) ;
			x /= 10 ;
		}
		x = sum ;
	}
	if(find(Happy, Happy+20, x) != Happy+20)
		return true ;
	return false ;
}

int main(){
	int number ;
	cin >> number ;
	if(ishappy(number))
		cout << number << " is a happy number" << endl ;
	else
		cout << number << " is not a happy number" << endl ;	
	return 0 ;
}
