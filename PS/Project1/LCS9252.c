#if 00
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
char fi[1005], se[1005], lcs[1001];
int dp[1005][1005], f, s, l, cnt;

int big(int a, int b) {
	if (a > b) return a;
	return b;
}
int ans;
int main() {
	scanf("%s", fi + 1);
	scanf("%s", se + 1);
	s = 1;
	while (se[s]) {
		f = 1;
		while (fi[f]) {
			if (se[s] == fi[f]) {
				dp[s][f] = dp[s - 1][f - 1] + 1;
			}
			else {
				dp[s][f] = big(dp[s - 1][f], dp[s][f - 1]);
			}
			if (ans < dp[s][f]) ans = dp[s][f];
			f++;
		}
		s++;
	}
	printf("%d\n", ans);

	int x = f-1, y = s-1, num = 0;

	while (dp[y][x]) {
		if (dp[y - 1][x] == dp[y][x]) {
			y--;
		}
		else if (dp[y][x - 1] == dp[y][x]) {
			x--;
		}
		else if (dp[y - 1][x - 1] == dp[y][x] - 1) {
			lcs[num++] = se[y];
			x--; y--;
		}
	}

	for (int i = ans - 1; i >= 0; i--) {
		printf("%c", lcs[i]);
	}

	return 0;
}

#endif
