#include <iostream>
#include <map>
using namespace std;


int main(){
    map<string,int> m;
    m["Apple"] = 12;
    m["Apple"] = 11;
    m["Kyrie"] = 70;
    m["Larry"] = 56;
    m["NTU"] = 112;

    map<string,int> ::iterator ptr;
    ptr = m.find("Apple");
    cout << ptr->second << endl;

    for(ptr = m.begin();ptr!=m.end();ptr++)
        cout << ptr->first << '\t' << ptr->second << endl;



    return 0;
}
