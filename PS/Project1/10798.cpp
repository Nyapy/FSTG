#if 0
#include <stdio.h>

char arr[5][16];
int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%s ", arr[i]);
	}

	for (int j = 0; j < 15; j++) {
		for (int i = 0; i < 5; i++) {
			if (arr[i][j])printf("%c", arr[i][j]);
		}
	}

}
#endif