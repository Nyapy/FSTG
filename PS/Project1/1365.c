#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int N;
int arr[100001];
int len[100001];
int mlen=0;

int binary(int n, int find) {
	int left, right, mid;
	left = 1, right = n;
	while (left < right) {
		mid = (left + right) / 2;
		if (len[mid] < find) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left;
}
int tem;
int main() {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (len[mlen] < arr[i]) {
			len[mlen + 1] = arr[i];
			mlen++;
		}
		else {
			tem = binary(mlen, arr[i]);
			len[tem] = arr[i];
		}
	}
	printf("%d", N - mlen);

	return 0;
}

#endif
