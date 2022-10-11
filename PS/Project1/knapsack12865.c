#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, K, W[101], V[101], dp[101][100000];

int big(int a, int b) {
	if (a > b) return a;
	return b;
}


int main() {

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &W[i], &V[i]);
		//dp[0][i] = 0;
		//dp[i][0] = 0;
	}
	int ans;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - W[i] >= 0) {	
				dp[i][j] = big(dp[i - 1][j], dp[i-1][j - W[i]] + V[i]);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	ans = dp[N][K];

	printf("%d", ans);
	return 0;
}

#endif
