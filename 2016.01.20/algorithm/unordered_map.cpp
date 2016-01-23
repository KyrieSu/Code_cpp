#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
	unordered_map<string, string> m;
	m["aaa"] = "AAA";
	m["bbb"] = "BBB";
	m["ccc"] = "CCC";
	m["ddd"] = "DDD";

	cout << m.find("aaa")->first << endl;
	cout << m.find("aaa")->second << endl;
}
