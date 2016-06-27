#include <iostream>
using namespace std;
int main(){
	int input;
	cin >> input;
	for(int i=0;;i++){
		if(i*i == input){
			cout<<"true";
			break;
		}
		if(i*i > input){
			cout<<"false";
			break;
		}
	}
	return 0;
} 
