#include<iostream>
#include<cstdlib>
#include<ctime> 
using namespace std;


int main(){
	int card[53]; /* card[0] -> ghost */
	/* 1~13 => �®� ; 14~26 ���� ; 27~39 ���j ; 40~52 ���� */
	for(int i=0;i<53;i++)
		card[i]=i;
	int player[4]={1,2,3,4};
	int mycard=53; //remain card
	int own_card[52];
	srand((unsigned)time(NULL));
	for(int i=1;i<53;i++){
		int index=rand()%mycard+1; // (0,1,2,...,card-1)+1
		own_card[i]=card[index];
		for(int k=index;k<mycard;k++)
			card[k]=card[k+1];
		mycard--;
	}
	int man=0;
	for(int k=1;k<53;k++){
		if(k%13==1){
			cout<<endl<<"===���a"<<player[man]<<"���P==="<<endl;
			man++; 
		}
	if(own_card[k]>=1&&own_card[k]<=13)
		cout<<"�®�"<<own_card[k];
	else if(own_card[k]>=14&&own_card[k]<=26)
		cout<<"����"<<own_card[k]%13+1;
	else if(own_card[k]>=27&&own_card[k]<=39)
		cout<<"���j"<<own_card[k]%13+1;
	else (own_card[k]>=40&&own_card[k]<=52);
		cout<<"����"<<own_card[k]%13+1;	
	}
	 
	
	return 0;
}
