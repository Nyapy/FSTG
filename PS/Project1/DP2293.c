#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, k, coin[101];
int dp[10002];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &coin[i]);
	}

	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}

	printf("%d", dp[k]);
	return 0;
}

#endif
