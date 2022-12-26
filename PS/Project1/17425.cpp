#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int T, hap[1000001], tem;

int main() {

	for (int i = 1; i < 1000001; i++) {
		tem = 1;
		while (i* tem < 1000001){
			hap[i * tem] += i;
			tem++;
		}
	}

	for (int i = 2; i < 1000001; i++) {
		hap[i] += hap[i - 1];
	}
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf(" %d", &tem);
		printf("%d\n", hap[tem]);
	}

	return 0;
}

#endif
