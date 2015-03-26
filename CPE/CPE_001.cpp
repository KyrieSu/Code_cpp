#include<iostream>
using namespace std;


int main(){
	int num,total=0,step[100]={0}; 
	while(true){
	int sum=0;
	cin>>num;
	if(num==0)
		break;	
	int *arr=new int [num];
	for(int i=0;i<num;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	int avg=sum/num; 
	for(int i=0;i<num;i++){
		if(arr[i]>avg)
			step[total]+=(arr[i]-avg);
	}
	delete [] arr;
	total++;
	}
	
	cout<<endl;
	for(int i=0;i<total;i++){
		cout<<"Set #"<<i+1<<endl;
		cout<<"The minimun step of moves is "<<step[i]<<endl<<endl;
	}
	
	return 0;
}
