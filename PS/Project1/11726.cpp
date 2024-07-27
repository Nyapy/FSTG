#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int dp[1001];

int tiling(int a) {
	if (dp[a]) return dp[a];
	return dp[a] = (tiling(a-2)+ tiling(a-1)) % 10007;
}
int n;
int main() {
	dp[1] = 1;
	dp[2] = 2;
	scanf("%d", &n);
	printf("%d", tiling(n));

	return 0;
}

#endif