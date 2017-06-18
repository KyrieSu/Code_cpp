#include <iostream>
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
        int x = gcd(c*abs(v1),v);
        if(c*v1%v!=0){
            int top = c*v1/x;
            int btm = v/x;
            if(v1<0){
                top = r*btm-abs(top);
            }
            if(top==0){
                cout << "0" << endl;
            }else{
                cout << top << "/" << btm << endl;
            }
        }else{
            int d1 = c*v1/v;
            if(v1>0){
                cout << d1 << endl;
            }else if(v1==0){
                cout << "0" << endl;
            }else{
                cout << r-d1 << endl;
            }
        }
    }
    return 0;
}