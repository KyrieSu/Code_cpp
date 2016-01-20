#include<iostream>
using namespace std;

long long dp[100];

int fib(int n){
	if(n == 1 || n == 2)
		return 1;
	return fib(n-1) + fib(n-2);
}

long long fib2(int n){
	if(dp[n] != -1){
		return dp[n];
	}
	dp[n] = fib2(n-1) + fib2(n-2);
	return dp[n];
}

void init(){
	for(int i=0 ; i<100 ; i++){
		dp[i] = -1;
	}
	dp[1] = dp[2] = 1;
	dp[0] = 0;
}

int main(){
	init();
	cout << fib2(50) << endl;	
}

