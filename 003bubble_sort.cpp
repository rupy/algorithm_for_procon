#include <iostream>

using namespace std;

static const int MAX = 100;

void printArray(int* A, int n){
	for (int i = 0; i < n - 1; ++i){
		printf("%d ", A[i]);
	}
	printf("%d\n", A[n - 1]);
}

int bubbleSort(int* A, int n){

	int sw = 0;
	for (int i = 0; i < n; ++i){
		for (int j = n - 1; i < j; --j){
			if (A[j - 1] > A[j]){
				swap(A[j - 1], A[j]);
				++sw;
				printArray(A, n);
			}
		}
	}
	return sw;
}

int main(){

	int A[MAX], n;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> A[i];
	}
	int sw = bubbleSort(A, n);
	printf("%d\n", sw);

	return 0;

}