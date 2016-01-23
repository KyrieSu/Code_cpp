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
    if(ptr!=m.end())
        cout << ptr->second << endl;
    else
        cout << "Can't find Apple" << endl ;

    m.insert(make_pair("Banana",100));
    cout << m["NTU"] << " HERE to get the second value " << endl;
    for(ptr = m.begin();ptr!=m.end();ptr++)
        cout << ptr->first << '\t' << ptr->second << endl;



    return 0;
}
