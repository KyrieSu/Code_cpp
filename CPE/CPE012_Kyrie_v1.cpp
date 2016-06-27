#include <iostream>
using namespace std;

bool square(int x){
    for(int i=1;x>0;i = i+2){
        x -= i;
        if(x==0)
            return true;
    }
    return false;
}

int main(){
    int x;
    cin >> x;
    cout << square(x) << endl;
    return 0;
}
