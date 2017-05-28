#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ED(string,string);

int main(){
    int a_len , b_len;
    string a,b;
    while(cin >> a_len >> a >> b_len >> b){
        cout << ED(a,b) << endl;
    }
    return 0;
}

int ED(string a , string b){
    int a_len = a.length()+1 , b_len = b.length()+1;
    int **arr = new int *[a_len];
    for(int i=0;i<a_len;i++){
        arr[i] = new int [b_len];
        for(int j=0;j<b_len;j++)
            arr[i][j] = 0;
    }
    
    for(int i=0;i<a_len;i++){
        for(int j=0;j<b_len;j++){
            if(i==0){
                arr[i][j] = j;
            }else if(j==0){
                arr[i][j] = i;
            }else if(a[i-1]==b[j-1]){
                arr[i][j] = arr[i-1][j-1];
            }else{
                arr[i][j] = min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]))+1; //increase one EDIT OPERATROR
            }
        }
    }
    
    int ans = arr[a.length()][b.length()];
    
    for(int i=0;i<a_len;i++)
            delete [] arr[i];
    delete []arr;

    return ans;
}
