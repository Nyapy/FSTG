#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, K;
long long dp[201][201];

int main() {
	scanf("%d %d", &N, &K);

	dp[0][0] = 1;
	for (int k = 1; k <= K; k++) {
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= i; j++) {
				dp[k][i] += dp[k - 1][j];
			}
			if (dp[k][i] > 1000000000) {
				dp[k][i] %= 1000000000;
			}
		}
	}

	printf("%d", dp[K][N]);

	return 0;
}

#endif
