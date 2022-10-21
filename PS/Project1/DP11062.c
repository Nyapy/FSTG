#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int T, N, cards[1000];
int dp[1000][1000];
int left, right, ans;

int big(int a, int b) {
	if (a > b) return a;
	return b;
}
int small(int a, int b) {
	if (a > b) return b;
	return a;
}

int game(int a[], int left, int right, int seq) {
	
	if (dp[left][right]) return dp[left][right];
	if (left == right) {
		if (seq) return a[left];
		else return 0;
	}

	if (seq) {
		return dp[left][right] = big(a[left] + game(a, left + 1, right, !seq), a[right] + game(a, left, right - 1, !seq));
	}
	else {
		return dp[left][right]= small(game(a, left + 1, right, !seq),game(a, left, right - 1, !seq));
	}
}

int main() {
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &cards[i]);
		}
		printf("%d\n", game(cards, 0, N - 1, 1));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dp[i][j] = 0;
			}
		}
	}
	return 0;
}

#endif
