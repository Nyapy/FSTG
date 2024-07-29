#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ctoi(char a[]) {
	int tem=0;
	int i = 0;
	while (a[i]) {
		tem *= 10;
		tem += (a[i++]-'0');
	}

	return tem;
}

int rev(int a) {
	int tem = 0;
	while (a) {
		tem *= 10;
		tem += a % 10;
		a /= 10;
	}
	return tem;
}

char a[1001], b[1001];

int main() {
	scanf("%s %s", &a, &b);
	printf("%d", rev(rev(ctoi(a)) + rev(ctoi(b))));
}

#endif