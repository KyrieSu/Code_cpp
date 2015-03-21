#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char str[200],*ptr;
int num,array[100];

int main(){
	cout<<"Enter 0 to end program"<<endl;
	int keyin,i;
	for(i=0;i>=0;i++){
	num=0;
	gets(str);
	if(str[0]=='0')
	 break;
	ptr = strtok(str," ") ;
	while(ptr != NULL){
		num++;
       	ptr = strtok(NULL," ") ;
    }
    array[i]=num;   
	}
	
	for(int j=0;j<i;j++)
		cout<<endl<<array[j]<<endl; 	
	
	
	return 0;
}
