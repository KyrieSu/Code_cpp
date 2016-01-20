#include<iostream>
#include<vector>
#include<string>
using namespace std;

int hash(string str){
	int sum = 0;
	for(int i=0 ; i<str.size() ; i++)
		sum += int(str[i]);
	return sum;
}

int main(){
	vector<string> vec;
	string str1("hello");
	string str2("hello world");
	string str3("hello larry");
	string str4("hello c++");
	vec.push_back(str1);
	vec.push_back(str2);
	vec.push_back(str3);
	vec.push_back(str4);

	vector<int> hashVal;
	hashVal.push_back(hash(str1));
	hashVal.push_back(hash(str2));
	hashVal.push_back(hash(str3));
	hashVal.push_back(hash(str4));

	string input;
	cin >> input;
	int hashInput = hash(input);

	for(int i=0 ; i<vec.size() ; i++){
		if(hashInput == hashVal[i]){
			if(input == vec[i]){
				cout << "yes" << endl;
				break;
			}
		}
	}
}
