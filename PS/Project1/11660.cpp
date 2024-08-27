#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, M, tem, a, b,c,d;
int arr[1025][1025];

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		a = 0;
		for (int j = 1; j <= N; j++) {
			scanf("%d", &tem);
			a += tem;
			arr[i][j] = arr[i-1][j]+ a;
		}
	}


	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", arr[c][d] - arr[c][b-1] - arr[a-1][d]+ arr[a-1][b-1]);
	}


	return 0;
}

#endif
