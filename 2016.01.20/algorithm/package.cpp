#include<iostream>
#include<algorithm>
using namespace std;

struct Fruit{
	int weight;
	int price;
	int happy;
};

int dp[51][501];	// [x][y] when have W=x M=y

void init(){
	for(int i=0 ; i<51 ; i++){
		for(int j=0 ; j<501 ; j++){
			dp[i][j] = -1;
		}
	}
}

int mostHappy2(Fruit arr[], int N, int W, int M){
	if(W <= 0 || M <= 0){
		return 0;
	}
	if(dp[W][M] != -1){
		return dp[W][M];
	}
	int temp[N];
	for(int i=0 ; i<N ; i++){
		if(W < arr[i].weight || M < arr[i].price)
			temp[i] = 0;
		else
			temp[i] = arr[i].happy + mostHappy2(arr, N, W-arr[i].weight, M-arr[i].price);
	}
	int res = temp[0];
	for(int i=1 ; i<N ; i++){
		res = max(res, temp[i]);
	}
	dp[W][M] = res;
	return res;
}

int mostHappy(Fruit arr[], int N, int W, int M){
	if(W <= 0 || M <= 0){
		return 0;
	}
	int temp[N];
	for(int i=0 ; i<N ; i++){
		if(W < arr[i].weight || M < arr[i].price)
			temp[i] = 0;
		else
			temp[i] = arr[i].happy + mostHappy(arr, N, W-arr[i].weight, M-arr[i].price);
	}
	int maxHappy = temp[0];
	for(int i=1 ; i<N ; i++){
		maxHappy = max(maxHappy, temp[i]);
	}
	return maxHappy;
}

int main(){
	init();
	int W, M;
	cin >> W >> M;

	int N;
	cin >> N;

	Fruit fruits[N];
	for(int i=0 ; i<N ; i++){
		cin >> fruits[i].weight;
		cin >> fruits[i].price;
		cin >> fruits[i].happy;
	}

	cout << mostHappy2(fruits, N, W, M) << endl;

}
