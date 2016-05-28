#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string str;
	vector<string> vec;
	while(getline(cin,str,'\n'))
		vec.push_back(str);
	reverse(vec.begin(),vec.end());
	int max_len = 0 , str_size = 0;
	for(int i=0;i<vec.size();i++){
		str_size = vec[i].size();
		if(str_size > max_len)
			max_len = str_size;
	}
	for(int i=0;i<max_len;i++){
		for(int j=0;j<vec.size();j++){
			if(i > vec[i].size())
				cout << " ";
			else
				cout << vec[j][i];
		}
		cout << endl;
	}
	return 0;
}
