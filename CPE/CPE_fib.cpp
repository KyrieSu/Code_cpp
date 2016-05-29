#include <iostream>
#include <string>
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
}

void inital(){
    for(int i=0;i<max;i++)
        dp[i] = -1;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=0;i<max;i++)
        fib(i);
}

int getindex(int x){
    for(int i=2;i<max;i++){
        if(dp[i] > x)
            return i-1;
        if(dp[i] == x)
            return i;
    }
}

string ans(int x,int index){
    string tmp;
    for(int i=index;i>1;i--){
        if(x>=dp[i]){
            x-=dp[i];
            tmp+="1";
        }
        else
            tmp+="0";
    }
    return tmp;
}


int main(){
    inital();
    int x, N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x;
        int index = getindex(x);
        string str = ans(x,index);
        cout << x << " = " << str << " (fib) " << endl;
    }
    return 0;
}
