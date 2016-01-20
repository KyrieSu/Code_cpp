#include<iostream>
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
	int maxVal = arrMax(arr, size);  // 10002 -> 4
	int minVal = arrMin(arr, size);  // 9998 -> 0

	int bucketSize = maxVal - minVal + 1;

	int bucket[bucketSize];  // 1 ~ 100  (101 = N+1)
	for(int i=0 ; i<bucketSize ; i++){
		bucket[i] = 0;
	}

	for(int i=0 ; i<size ; i++){  // O(size)
		bucket[arr[i]-minVal]++;
	}
	
	int arrIndex = 0;
	for(int i=0 ; i<bucketSize ; i++){  // O(bucket_size)
		while(bucket[i] > 0){
			arr[arrIndex] = i+minVal;
			arrIndex++;
			bucket[i]--;
		}
	}
}

int main(){
	int arr1[] = {10, 5, 6, 4, 2, 100, 7, 65, 46, 99, 98, 98};
	int arr2[] = {10000, 10001, 10002, 9999, 9998};
	// 9998 -> 1
	// 10002 -> 5
	bucketSort(arr1, sizeof(arr1)/sizeof(int));
	for(int i=0 ; i<sizeof(arr1)/sizeof(int) ; i++)
		cout << arr1[i] << " ";
	cout << endl;


	bucketSort(arr2, sizeof(arr2)/sizeof(int));
	for(int i=0 ; i<sizeof(arr2)/sizeof(int) ; i++)
		cout << arr2[i] << " ";
	cout << endl;
}
