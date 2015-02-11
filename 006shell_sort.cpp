#include <iostream>

using namespace std;

void printArray(int* A, int n){
	for (int i = 0; i < n - 1; ++i){
		printf("%d ", A[i]);
	}
	printf("%d\n", A[n - 1]);
}

void insertionSort(int* A, int n, int h){
	for (int i = h; i < n; ++i){
		for(int j = i - h;0 <= j && A[j] > A[j + h] ;j -= h){
			swap(A[j], A[j + h]);
			printArray(A, n);
		}
	}
}

void shellSort2(int* A, int n){

	for (int h = n / 2; 0 < h; h /= 2){
		insertionSort(A, n, h);
	}
}


void shellSort(int* A, int n){

	for (int h = n / 2; 0 < h; h /= 2){
		for (int i = h; i < n; ++i){
			for (int j = i - h; 0 <= j && A[j] > A[j + h]; j -= h){
				swap(A[j], A[j + h]);
				printArray(A, n);
			}
		}
	}
}

int main(){

	int A[MAX], n;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> A[i];
	}
	shellSort2(A, n);

	return 0;

}