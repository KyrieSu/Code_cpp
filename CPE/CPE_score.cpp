#include<string>
#include<iostream>
using namespace std;

int main(){
	int num;
	cin>>num;
	string *str=new string [num];
	int *data=new int [num];
	for(int i=0;i<num;i++){
		data[i]=0;
		cin>>str[i];
		int len=str[i].size();
		int score=0;
		for(int j=0;j<len;j++)
			if(str[i][j]=='O'){
				score++;
				data[i]+=score;
			}
			else
				score=0;
	}
	for(int i=0;i<num;i++)
		cout<<data[i]<<endl;
	delete[]str;
	delete[]data;
	
	return 0;
}
