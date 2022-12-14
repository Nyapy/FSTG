#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int T,N, arr[501], len[501], mlen, tem, ans;

int binary(int ml, int find) {
	int left = 1, right = ml, mid;

	while (left < right) {
		mid = (left + right) / 2;

		if (len[mid] >= find) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
		}
		ans = 0;
		for (int i = 1; i <= N; i++) {
			mlen = 0;
			for (int j = i; j <= N; j++) {
				if (len[mlen] < arr[j]) {
					len[mlen + 1] = arr[j];
					mlen++;
				}
				else {
					tem = binary(mlen, arr[j]);
					len[tem] = arr[j];
				}
				ans += mlen;
			}
		}
		printf("Case #%d: %d", tc, ans);
	}
	return 0;
}

#endif
