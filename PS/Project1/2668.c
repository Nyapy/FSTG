#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, visited[101], down[101], tail[101], area[101];
int ans;

int findtail(int now) {
	if (now == down[now]) return tail[now]= now;

	if (!visited[down[now]]) {
		visited[down[now]] = 1;
		return tail[now]= findtail(down[now]);
	}
	else {
		return tail[now] = down[now];
	}
}
int cnt, cand[101], num = 0;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &down[i]);
	}
	
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			findtail(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (tail[i] == i) {
			cnt = 1;
			int next = down[i];
			cand[i] = 1;
			while (i != next) {
				cnt++;
				cand[next] = 1;
				next = down[next];
			}
			ans += cnt;
		}
	}

	printf("%d\n", ans);
	for (int i = 1; i <= N; i++) {
		if (cand[i]) {
			printf("%d\n", i);
		}
	}
	return 0;
}

#endif
