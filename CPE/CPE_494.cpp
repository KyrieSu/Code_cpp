#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char str[200],*ptr,input[100][30];
int num,array[100];

int main(){
	cout<<"mayday~ I can't so the ultimate loop.....But my test is great '"<<endl;
	int keyin;
	num=0;
	gets(str);
	ptr = strtok(str," ") ;
	while(ptr != NULL){
		num++;
       	ptr = strtok(NULL," ") ;
    }
   	cout<<num<<endl;
	
	
	return 0;
}
