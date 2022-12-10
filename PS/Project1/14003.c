#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int N;
int A[1000001];
int len[1000001];
int mlen=0;
int trace[1000001];

int binary(int ml, int find) {
	int left = 1, right = ml;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;

		if (A[len[mid]] < find) {
			left = mid+1;
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
		scanf("%d", &A[i]);
	}
	A[0] = -1000000001;
	for (int i = 1; i <= N; i++) {
		if (A[len[mlen]] < A[i]) {
			len[mlen + 1] = i;
			trace[i] = len[mlen];
			mlen++;
		}
		else {
			tem = binary(mlen, A[i]);
			trace[i] = len[tem-1];
			len[tem] = i;
		}
	}

	printf("%d\n", mlen);
	tem = len[mlen];
	for (int i = 1; i <= mlen; i++) {
		len[i] = A[tem];
		tem = trace[tem];
	}
	for (int i = mlen; i >= 1; i--) {
		printf("%d ", len[i]);
	}
	return 0;
}

#endif