#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int T, N, arr[100001], len[100001], mlen, tem, ans;

int binary(int ml, int find) {
	int left = 1, right = ml, mid;

	while (left < right) {
		mid = (left + right) / 2;

		if (len[mid] > find) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	while(1) {
		scanf(" %d", &N);
		if (N == '\0') break;
		for (int i = 1; i <= N; i++) {
			scanf(" %d", &arr[i]);
		}
		ans = 0;

		mlen = 0;
		for (int j = 1; j <= N; j++) {
			if (len[mlen] < arr[j]) {
				len[mlen + 1] = arr[j];
				mlen++;
			}
			else {
				tem = binary(mlen, arr[j]);
				len[tem] = arr[j];
			}
			
		}
		printf("%d\n", mlen);
	}
	return 0;
}

#endif
