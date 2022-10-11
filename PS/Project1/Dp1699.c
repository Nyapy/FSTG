#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, dp[317][100001];

int small(int a, int b) {
	if (a == 0) return b;
	if (a < b) return a;
	return b;
}

int main() {
	scanf("%d", &N);

	int s = 1;
	int tem;



	while (s * s <= N) {
		if ((s + 1) * (s + 1) > N) break;
		s++;
	}
	for (int i = 1; i <= N; i++) dp[1][i] = i;
	for (int i = 2; i <= s; i++) {
		for (int j = 1; j <= N; j++) {
			if (j >= (i * i)) {
				dp[i][j] = small(dp[i - 1][j], dp[i][j - (i * i)] + 1);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%d", dp[s][N]);
	return 0;
}
#endif
