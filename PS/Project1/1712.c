#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int a, b, c;
int main() {

	scanf("%d %d %d", &a, &b, &c);

	if (c - b <= 0) {
		printf("-1");
	}
	else {
		printf("%d", (a/(c-b)) +1);
	}

	return 0;
}

#endif
