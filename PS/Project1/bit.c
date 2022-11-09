#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int M, N, K;
long long l[2];
int i[2];

int main() {
	int cnt = 1;
	l[0] = 1;
	i[0] = 1;

	while (cnt <= 33) {
		printf("int %d: %d %d\n", cnt, i[0], i[1]);
		printf("==========================\n");
		i[0] <<= 1;
		cnt++;
	}
	/*while (cnt <= 65) {
		printf("long %d: %lld\n", cnt, l);
		printf("int  %d: %d\n", cnt, i);
		printf("==========================\n");
		l <<= 1;
		i <<= 1;
		cnt++;
	}*/
	return 0;
}

#endif
