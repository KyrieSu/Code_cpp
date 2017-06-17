#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a , int b){
    return a ? gcd(b%a,a) : b;
}

int main(){
    int r , v1 , v2 ;
    while(cin >> r >> v1 >> v2){
        if(r==0) break;
        int v = v1-v2;
        r/=2;
        int x = gcd(r*v1,v);
        if(x==v){
            cout << abs(r*v1/x) << endl;
        }else{
            cout << abs(r*v1/x) << "/" << abs(v/x) << endl;
        }
    } 
    return 0;
}