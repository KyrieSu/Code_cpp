#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char *reverse(char str[]){
	int num=strlen(str);
	char *rev=new char [num+1];
	for(int i=0;i<num;i++)
		rev[i]=str[num-(i+1)];
	
	return rev;	
}



int main(){
	char str[50];
	cout<<"�п�J�^��r�� : ";
	gets(str);
	char *arr=reverse(str);
	cout<<"�r�������� :"<<endl; 
	puts(arr);
	
	return 0;
}
