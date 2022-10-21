#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N;
int liquid[100000], temp[100000];

void merge(int a[], int left, int right) {
	int mid = (left + right) / 2;
	int i = left, j = mid + 1, k =left;

	while (i <= mid && j <= right) {
		if (a[i] > a[j]) temp[k++] = a[j++];
		else temp[k++] = a[i++];
	}

	while (i <= mid) temp[k++] = a[i++];
	while (j <= right) temp[k++] = a[j++];
	k = left;

	while (k <= right) {
		a[k] = temp[k];
		k++;
	}
}

void mergeSort(int a[], int left, int right) {
	if (left == right) return;
	int mid = (left + right) / 2;

	mergeSort(a, left, mid);
	mergeSort(a, mid + 1, right);
	merge(a, left, right);
}
int min = 2000000001;
int ans1, ans2;

int abs(int a) {
	if (a > 0) return a;
	return -a;
}

int lower(int a[],int left, int right, int find) {
	int mid;
	int sum;
	int le = left, ri = right;

	while (le < ri) {
		mid = (le + ri) / 2;
		sum = a[left - 1] + a[mid];
		if (abs(sum) < min) {
			min = abs(sum);
			ans1 = left - 1;
			ans2 = mid;
		}
		if (sum >= 0) ri = mid;
		else le = mid + 1;
	}
	return le;

}

int sum = 2000000001, tem;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &liquid[i]);
	}
	mergeSort(liquid, 0, N-1);
	int tem;

	for (int i = 0; i <= N/2; i++) {
		tem = lower(liquid, i + 1, N, -liquid[i]);
	}
	printf("%d %d", liquid[ans1], liquid[ans2]);
	return 0;
}

#endif