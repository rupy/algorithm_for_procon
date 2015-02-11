#include <iostream>

using namespace std;
static const int MAX = 100;

void printArray(int* A, int n){
	for (int i = 0; i < n - 1; ++i){
		printf("%d ", A[i]);
	}
	printf("%d\n", A[n - 1]);
}

int selectionSort(int* A, int n){

	int sw = 0;
	for (int i = 0; i < n - 1; ++i){
		int min_i = i;
		for (int j = i + 1; j < n; ++j){
			if (A[min_i] > A[j]) min_i = j;
		}
		if (min_i != i){
			 swap(A[i], A[min_i]);
			 ++sw;
		}
		printArray(A, n);
	}
	return sw;
}

int main(){

	int A[MAX], n;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> A[i];
	}
	int sw = selectionSort(A, n);
	printf("%d\n", sw);

	return 0;

}