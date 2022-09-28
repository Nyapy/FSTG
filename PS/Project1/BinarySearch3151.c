#if 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int N, A[10000];
int temp[10000];
void merge(int left, int right) {

	int i = left, j = (left + right) / 2 + 1;
	int k = left;
	while (i <= (left + right) / 2 && j <= right) {
		if (A[i] <= A[j]) {
			temp[k++] = A[i++];
		}
		else {
			temp[k++] = A[j++];
		}
	}

	while (i <= (left + right) / 2) {
		temp[k++] = A[i++];
	}
	while (j <= right) {
		temp[k++] = A[j++];
	}

	k = left;
	while (k <= right) {
		A[k] = temp[k];
		k++;
	}


}

void mergeSort(int left, int right) {
	if (left == right) {
		return;
	}
	mergeSort(left, (left + right) / 2);
	mergeSort((left + right) / 2 + 1, right);
	merge(left, right);

}


int lower(int left, int right, int*a, int find) {
	int mid;
	int l = left, r = right;

	while (l < r) {
		mid = (l + r) / 2;

		if (a[mid] >= find) {
			r = mid;
		}
		else {
			l = mid+1;
		}
	}
	return l;
}
int upper(int left, int right, int* a, int find) {
	int mid;
	int l = left, r = right;

	while (l < r) {
		mid = (l + r) / 2;

		if (a[mid] <= find) {
			l = mid+1;
		}
		else {
			r = mid;
		}
	}
	return l;
}

int main() {

	scanf(" %d", &N);

	for (int i = 0; i < N; i++) {
		scanf(" %d", &A[i]);
	}

	mergeSort(0, N - 1);

	long long ans = 0;
	int val;
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N-1; j++) {
			val = -(A[i] + A[j]);
			ans += upper(j + 1, N, A, val)- lower(j + 1, N, A, val);
		}
	}

	printf("%lld", ans);

	return 0;
}

#endif