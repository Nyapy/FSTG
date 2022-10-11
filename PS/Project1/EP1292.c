#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int A, B, sum[1001];

int main() {
	scanf("%d %d", &A, &B);
	int a = 1;
	int j = 1;
	sum[0] = 0;
	while (1) {
		for (int i = 0; i < a; i++) {
			sum[j] = sum[j-1]+a;
			j++;
			if (j == B+1) break;
		}
		if (j == B+1) break;
		a++;

	}
	printf("%d", sum[B] - sum[A-1]);

	return 0;
}

#endif
