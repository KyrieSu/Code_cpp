#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int arrMax(int arr[], int size){
	int res = arr[0];
	for(int i=1 ; i<size ; i++){
		res = max(arr[i], res);
	}
	return res;
}

int arrMin(int arr[], int size){
	int res = arr[0];
	for(int i=1 ; i<size ; i++){
		res = min(arr[i], res);
	}
	return res;
}

void bucketSort(int arr[], int size){
	int maxVal;
	int minVal;

	int bucket[101];  // 1 ~ 100  (101 = N+1)
	memset(bucket, 0, 101);

	for(int i=0 ; i<size ; i++){  // O(size)
		bucket[arr[i]]++;
	}
	
	for(int i=0 ; i<101 ; i++)
		cout << bucket[i] << " ";
	cout << endl;

	int arrIndex = 0;
	for(int i=1 ; i<=100 ; i++){  // O(bucket_size)
		while(bucket[i] > 0){
			cout << i << endl;
			arr[arrIndex] = i;
			arrIndex++;
			bucket[i]--;
		}
	}
}

int main(){
	int arr[] = {10, 5, 6, 4, 2, 100, 7, 65, 46, 99, 98, 98};
	//int arr = {10000, 10001, 10002, 9999, 9998};
	// 9998 -> 1
	// 10002 -> 5
	bucketSort(arr, sizeof(arr)/sizeof(int));
}
