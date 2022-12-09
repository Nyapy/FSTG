#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arr[1000], tem[1000];

void merge(int left, int right) {
	int i = left, mid = (left + right) / 2, j = mid + 1;
	int t=left;
	while (i <= mid && j <= right) {
		if (arr[i] > arr[j]) {
			tem[t++] = arr[j++];
		}
		else {
			tem[t++] = arr[i++];
		}
	}
	while (i <= mid) {
		tem[t++] = arr[i++];
	}
	while (j <= right) {
		tem[t++] = arr[j++];
	}
	for (int k = left; k <= right; k++) {
		arr[k] = tem[k];
	}
}

void mergesort(int left, int right) {
	if (left == right) return;
	mergesort(left, (left + right) / 2);
	mergesort(((left + right) / 2)+1, right);
	merge(left, right);
}

int N;
int main() {
	
	scanf("%d", &N);
	for (int i = 0; i < N; i ++ ) {
		scanf("%d", &arr[i]);
	}
	mergesort(0, N-1);
	int now = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] <= now + 1) now += arr[i];
		else break;
	}
	printf("%d", now + 1);
	return 0;
}

#endif
