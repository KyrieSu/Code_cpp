#include<iostream>
using namespace std;

int main(){
	int num,sum=0,avg,step=0;
	cin>>num;
	int *arr=new int [num];
	for(int i=0;i<num;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	avg=sum/num;
	for(int i=0;i<num;i++){
		if(arr[i]>avg)
			step+=(arr[i]-avg);
	}
	cout<<"The minimum step of moves is "<<step<<"."<<endl;
	delete [] arr;
	
	return 0;
}
