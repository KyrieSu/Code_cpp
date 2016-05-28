#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define max 40


int dp[max];

int fib(int x){
    if(dp[x]!=-1)
        return dp[x];
    else{
        dp[x] = fib(x-1) + fib(x-2);
        return dp[x];
    }
    cout << x;
}

void inital(){
    memset(dp,max,-1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=0;i<max;i++)
        fib(i);
}

int getindex(int x){
    int i;
    for(i=0;i<max;i++)
        if(dp[i] > x)
            break;
    return i-1;
}

int main(){
    inital();
    int x;
    while(cin >> x){
        int index = getindex(x);
        cout << index;
    }
    return 0;
}
