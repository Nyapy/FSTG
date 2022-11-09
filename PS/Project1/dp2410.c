#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, k, dp[25][1000001];
int myuk=1;
int main() {

	scanf("%d", &N);

	while (myuk <= N) {
		myuk *= 2;
	}
	myuk /= 2;

	k = 2;
	int cnt = 1;
	
	for (int i = 0; i <= N; i++) dp[0][i] = 1;

	while (k <= N) {
		for (int i = 0; i <= N; i++) {
			if (i < k) {
				dp[cnt][i] = dp[cnt - 1][i];
			}
			else {
				dp[cnt][i] = dp[cnt][i - k] + dp[cnt - 1][i];
			}
			if (dp[cnt][i] > 1000000000) dp[cnt][i] %= 1000000000;
		}
		cnt += 1;
		k *= 2;
	}


	printf("%d", dp[cnt - 1][N]);


	return 0;
}

#endif
