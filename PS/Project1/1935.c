#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int num[26];
double stack[100];
int N, s = 0;
double a,b, c;
char sic[101], tem;
int seq=0;

int main() {
	
	scanf(" %d", &N);
	scanf(" %s", sic);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	
	while (1) {
		tem = sic[seq++];
		if (tem == '\0') break;

		if (tem >= 'A' && 'Z' >= tem) {
			stack[s++] = num[tem - 'A'];
		}
		else {
			a = stack[--s];
			b = stack[--s];

			if (tem == '+') {
				c = a + b;
			}
			else if (tem == '-') {
				c = b - a;
			}
			else if (tem == '*') {
				c = a * b;
			}
			else {
				c = b / a;
			}
			stack[s++] = c;
		}
	}
	printf("%.2lf", stack[0]);
	return 0;
}
#endif