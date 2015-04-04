#include<iostream>
#include<vector>
using namespace std ;

void printList(vector<int> *list, int N){
	for(int i=1 ; i<=N ; i++){
		cout << i << ":" ;
		for(int j=0 ; j<list[i].size() ; j++)
			cout << list[i][j] << " " ;
		cout << endl ;
	}
}

int main(){
	int N ;		// number of dot
	cin >> N ;
	vector<int> list[N+1] ;
	while(1){
		int src, dst ;
		cin >> src >> dst ;
		if(src == 0 || dst == 0)
			break ;
		list[src].push_back(dst) ;
	}
	printList(list, N) ;
}
