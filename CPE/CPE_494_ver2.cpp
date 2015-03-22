#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctype.h>
using namespace std;

char str[200],*ptr;
int num,array[100];

int main(){
	cout<<"Enter 0 to end program"<<endl;
	int i;
	for(i=0;i>=0;i++){
		num=0;
		gets(str);
		if(str[0]=='0')
	 		break;
		ptr = strtok(str," ") ;
		while(ptr != NULL){
			if(isalpha(*ptr)) 
				num++;
       		ptr = strtok(NULL," ") ;
    	}
    	array[i]=num;   
	}
	
	for(int j=0;j<i;j++)
		cout<<endl<<array[j]<<endl; 	
	
	
	return 0;
}
