#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, M, tem, a,b;
int arr[100001];

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &tem);
		arr[i] = arr[i-1] + tem;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", arr[b] - arr[a - 1]);
	}

	
	return 0;
}

#endif
