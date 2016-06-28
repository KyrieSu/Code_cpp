#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void inital(unordered_map<int,string>& m){
    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tuv";
    m[0] = "wxyz";
}


int main(){
    unordered_map<int,string> m;
    inital(m);
    int x , tmp;
    cin >> x; //input integer
    vector<string> v;
    while(x){
        v.push_back(m[ x%10 ]);
        x /= 10;
    }
    reverse(v.begin(),v.end()); //cause we need to reverse the order
    vector<int> buf; //store size of every string in v
    for(int i=0;i<v.size();i++)
        buf.push_back(v[i].size());
    
    return 0;
}
