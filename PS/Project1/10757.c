#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char A[10001] = { 0 }, B[10001] = { 0 }, C[10001] = {0}, tem;

int reverse(char a[]) {
	int len=0;
	while (a[len++]) {
	}
	len--;
	
	char tem;
	for (int i = 0; i < len / 2; i++) {
		tem = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = tem;
	}
	//printf("%s", a);
	return(len);
}

int main() {
	scanf(" %s", A);
	int lenA=reverse(A);
	scanf(" %s", B);
	int lenB=reverse(B);

	int large = lenA > lenB ? lenA : lenB;

	for (int i = 0; i < large; i++) {
		if (!A[i]) A[i] = '0';
		if (!B[i]) B[i] = '0';
		tem = C[i]+A[i] + B[i] - '0' - '0';

		if (tem >= 10) {
			C[i + 1]++;
			if (tem - 10) {
				C[i] = tem + '0' - 10;
			}
			else {
				C[i] = '0';
			}
		}
		else {
			C[i] = tem + '0';
		}
	}
	if (C[large]) {
		C[large] += '0';
	}

	reverse(C);

	printf("%s", C);
	
	return 0;
}

#endif