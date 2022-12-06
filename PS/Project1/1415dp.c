#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int N;
int candy[10001], candynum[50], candycnt = 0;
int a,  largest = 0;
char sosu[500001];
long long dp[500001], ans;
int zero;
int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		candy[a] ++;
		if (a == 0) {
			zero++;
			continue;
		}
		if (largest < a) largest = a;
	}

	int idx = 2;
	while (idx <= 500000) {
		if (sosu[idx]) {
			idx++;
			continue;
		}
		else {
			int j = 2;
			while (j * idx <= 500001) {
				sosu[j * idx] = 1;
				j++;
			}
			idx++;
		}
	}

	int tem = 0;
	for (int i = 0; i < 10001; i++) {
		if (candy[i]) {
			candynum[tem++] = i;
			candycnt++;
		}
	}

	dp[0] = 1;
	for (int i = 0; i < candycnt; i++) {
		for (int j = largest * N; j > 0; j--) {
			for (int k = 1; k <= candy[candynum[i]]; k++) {
				if (j - candynum[i] * k < 0) break;
				dp[j] += dp[j - candynum[i] * k];
			}
		}
	}

	for (int i = 2; i <= N * largest; i++) {
		if (!sosu[i]) ans += dp[i];
	}
	printf("%lld", ans*(zero+1));


	return 0;
}
#endif