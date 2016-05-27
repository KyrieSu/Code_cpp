#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

unordered_map<int,unsigned long long int> m;

unsigned long long int fac(int x){
    if(m[x]!=0)
        return m[x];
    else
        m[x] = fac(x-1)*x;
    return m[x];
}

int cal(double x){
    int count = 0;
    while(x>=10){
        x /= 10 ;
        count++;
    }
    return count + 1; // digit = log(x) + 1
}



int main(){
    m[0] = 1; m[1] = 1;
    for(int i=0;i<50;i++)
        cout << fac(i) << endl;
    return 0;
}
