#include <iostream>

using namespace std;

static const int MAX = 100;


void printArray(int* A, int n){
	for (int i = 0; i < n - 1; ++i){
		printf("%d ", A[i]);
	}
	printf("%d\n", A[n - 1]);
}

void insertionSort(int* A, int n){

	for (int i = 1; i < n; ++i){
		for (int j = i - 1; 0 <= j && A[j] > A[j + 1]; --j){
			swap(A[j], A[j + 1]);
		}
		printArray(A, n);
	}
}

int main(){

	int A[MAX], n;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> A[i];
	}
	insertionSort(A, n);

	return 0;

}