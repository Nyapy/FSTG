#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int N;
int candy[10001], candynum[50], candycnt=0;
int a, ans =0, largest=0;
char sosu[500001];

void dfs(int idx, int su) {
	if (idx == candycnt) return;
	if (candy[candynum[idx]]) {

		for (int i = 0; i <= candy[candynum[idx]]; i++) {
			if (i >0 && su + (i * candynum[idx]) >= 2 && !sosu[su + (i * candynum[idx])]) ans += 1;
			dfs(idx+1, su + (i * candynum[idx]));
		}
	}
	else {
		dfs(idx + 1, su);
	}
	return;
}


int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		candy[a] ++;
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

	int tem=0;
	for (int i = 0; i < 10001; i++) {
		if (candy[i]) {
			candynum[tem++] = i;
			candycnt++;
		}
	}

	dfs(0, 0);

	printf("%d", ans);


	return 0;
}
#endif