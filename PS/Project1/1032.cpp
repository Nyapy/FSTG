#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

char ans[51], tem[51];
int N;

int main() {
	scanf("%d", &N);
	scanf("%s", ans);
	for (int i = 1; i < N; i++) {
		scanf("%s", tem);
		int j = 0;
		while (tem[j]) {
			if (tem[j] != ans[j]) {
				ans[j] = '?';
			}
			j++;
		}
	}

	printf("%s", ans);
}

#endif