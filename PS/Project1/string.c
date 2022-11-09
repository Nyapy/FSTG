#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


char N[10];
int K, visited[11][1000001];

char* itos(int in, char* temp) {
	int i = 0;
	while (in) {
		temp[i++] = (in % 10) + 48;
		in /= 10;
	}
	temp[i] = '\n';
	return temp;
}

int stoi(char* temp) {
	int ret = 0, len = 0;
	while (temp[len++]) {}
	len--;
	int jari = 1;
	for (int i = len - 1; i >= 0; i--) {
		ret += jari * (temp[i] - '0');
		jari *= 10;
	}
	return ret;
}

int ans = 0;

int main() {
	//scanf("%s %d", &N, &K);
	char tem[10];
	for (int i = 0; i < 10; i++) {
		tem[i] = 0;
	}

	for (int i = 0; i < N; i++) {

	}


	printf("%s", itos(156, tem));
	printf("%d", stoi("12355"));

	return 0;
}

#endif
