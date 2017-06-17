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
        int c = r/2;
        int x = gcd(c*v1,v);
        if(c*v1%v!=0){
            int top = c*v1/x;
            int btm = v/x;
            if(btm<0){
                top *=-1;
                btm *=-1;
            }
            cout << top << "/" << btm << endl;
        }else{
            cout << c*v1/v << endl;
        }
    }
    return 0;
}