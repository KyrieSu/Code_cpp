#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct Fruit{
	int weight;
	int price;
	int happy;
};

typedef map<int, int> Array1D;
typedef map<int, Array1D> Array2D;

Array2D dp;	// [x][y] when have W=x M=y

int mostHappy2(Fruit arr[], int N, int W, int M){
	if(W <= 0 || M <= 0){
		return 0;
	}
	if(dp[W][M] != 0){
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
