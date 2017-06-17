#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a ,int b){
    return a ? gcd(b%a,a) : b;
}

int main(){
    int r , v1 , v2 ;
    while(cin >> r >> v1 >> v2){
        if(r==0) break;
        int v = 0;
        if(v1>v2){
            v = v1-v2;
        }else{
            v = v2-v1;
        }
        r/=2;
        int x = gcd(r*v1,v);
        if(r*v1%v!=0){
            int top = r*v1/x;
            int btm = v/x;
            if(v1<0){
                top = 400*btm - top;
            }
            cout << abs(top) << "/" << btm << endl;
        }else{
            int y = r*v1/v;
            if(v1<0){
                y -= 400-y;
            }
            cout << abs(y) << endl;
        }
    }
    return 0;
}