#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

string sel(string s){
    string ans;
    for(int i=0;i<s.size();i++)
        if(isalpha(s[i]))
                ans+=s[i];
    return ans;
}


int main(){
    string str;
    while(getline(cin,str,'\n')){
        unordered_map<char,int> m;
        string tmp = sel(str);
        for(int i=0;i<tmp.size();i++)
            m[tmp[i]]++;
        unordered_map<char,int>::iterator ptr;
        int max = 0;
        for(ptr=m.begin();ptr!=m.end();ptr++)
            if(ptr->second > max)
                max = ptr->second;
        string sol;
        for(ptr=m.begin();ptr!=m.end();ptr++)
            if(ptr->second==max)
                sol+=ptr->first;
        sort(sol.begin(),sol.end());
        cout << sol << ' ' << max << endl;
    }
    return 0;
}
