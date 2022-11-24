#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N;
char arr[81];


int check(int size) {
	if (size <= 1) return 0;
	int li = size / 2;
	int flag;
	for (int i = 1; i <= li; i++) {
		flag = 1;
		for (int j = 0; j < i; j++) {
			if (arr[size - (2 * i) + j] != arr[size - i + j]) { 
				flag = 0; 
				break ;
			}
		}
		if (flag) return 1;
	}

	return 0;


}

int aflag = 0;
void dfs(int s) {
	if (aflag) return;
	if (check(s)) return;
	if (s == N) {
		aflag = 1;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		arr[s] = i+'0';
		dfs(s + 1);
		if (aflag) return;
	}
}


int main() {

	scanf("%d", &N);
	dfs(0);

	printf("%s", arr);
	return 0;
}

#endif
