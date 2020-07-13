#include <stdio.h>
#include <stdlib.h>

void Swap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int Partition(int arr[], int left, int right) {

	int pivot = arr[left]; 
	int low = left + 1;
	int high = right;

	while (low <= high){ 
		while (low <= right && pivot >= arr[low]) low++;
		while (high >= (left + 1) && pivot <= arr[high]) high--; 
		if (low <= high){
			Swap(arr, low, high);  
		}
	}
	Swap(arr, left, high); 
	return high; 
}

//Äü¼ÒÆ®
void QuickSort(int arr[], int left, int right){
	if (left <= right){
		int pivot = Partition(arr, left, right); 
		QuickSort(arr, left, pivot - 1); 
		QuickSort(arr, pivot + 1, right); 
	}
}

void min_queue() {
	int N;
	int *arr;
	int sum = 0;
	int sum2 = 0;
	scanf("%d", &N);
	arr = (int *)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	QuickSort(arr, 0, N - 1);
	for (int i = 0; i < N; i++) {
		sum += arr[i];
		sum2 += sum;
	}
	printf("%d", sum2);

	free(arr);
}

int main() {
	min_queue();
}

