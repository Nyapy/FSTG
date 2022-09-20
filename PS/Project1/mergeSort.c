
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int A[] = {1, 65, 35, 44, 15, 33, 18, 100, 2597, 123, 122, 5};

void merge(int left, int mid, int right) {
	int i=left, j=mid+1, k=0;
	int* tem = (int*)malloc(sizeof(int) * (right+left+1));

	while (i <= mid && j <= right) {
		if (A[i] <= A[j]) {
			tem[k++] = A[i++];
		}
		else {
			tem[k++] = A[j++];
		}
	}
	while (i <= mid) {
		tem[k++] = A[i++];
	}
	while (j <= right) {
		tem[k++] = A[j++];
	}
	k = 0;
	for (int a = left; a <= right; a++) {
		A[a] = tem[k++];
	}
	free(tem);
}

void mergeSort(int left, int right, int a[]) {
	if (left == right) {
		return;
	}

	int mid = (left + right) / 2;

	mergeSort(left, mid, a);
	mergeSort(mid + 1, right, a);

	merge(left, mid, right);
}


int main() {
	int size = sizeof(A) / sizeof(int);

	mergeSort(0, size - 1, A);

	for (int i = 0; i < size; i++) {
		printf("%d ", A[i]);
	}
}


#endif