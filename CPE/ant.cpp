#include <iostream>
using namespace std;



int main(){
    int n,len;
    cin >> n >> len;
    int max = 0 , d = 0;
    int x , v; // v: 0->left ; 1->right
    for(int i=0;i<n;i++){
        cin >> x >> v;
        if(v==1)
            d = len - x;
        else
            d = x ;
        if(d > max)
            max = d;
    }
    cout << max << endl;

    return 0;
}
