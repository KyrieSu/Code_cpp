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
    for(int i=0;i<max;i++){
        if(dp[i] > x)
            return i-1;
        if(dp[i] == x)
            return i;
    }
}

queue<int> ans(int x,int index){
    queue<int> data;
    for(int i=index;i>1;i--){
        if(x>=dp[i]){
            x-=dp[i];
            data.push(1);
        }
        else
            data.push(0);
    }
    return data;
}

void print(int x,queue<int> Q){
    cout << x << " = " ;
    if(x==1) cout << 1; //special case // I will write this case in issue#5
    while(!Q.empty()){
        cout << Q.front();
        Q.pop();
    }
    cout << " (fib) " << endl;
}

int main(){
    inital();
    int x, N;
    queue<int> Q; //store element 0 or 1
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x;
        int index = getindex(x);
        Q = ans(x,index);
        print(x,Q);
    }
    return 0;
}
