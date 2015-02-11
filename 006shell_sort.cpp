#include <iostream>

using namespace std;

static const int MAX = 100;

void printArray(int* A, int n){
	for (int i = 0; i < n - 1; ++i){
		printf("%d ", A[i]);
	}
	printf("%d\n", A[n - 1]);
}

int shellSort(int* A, int n){

	int sw = 0;
	for (int h = n / 2; 0 < h; h /= 2){
		for (int i = h; i < n; ++i){
			for (int j = i - h; 0 <= j && A[j] > A[j + h]; j -= h){
				swap(A[j], A[j + h]);
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
	int sw = shellSort(A, n);
	printf("%d\n", sw);

	return 0;

}