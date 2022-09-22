#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int size = 10;
int arr[10] = { 20, 1, 21, 6, 6, 5, 15, 7, 2, 32 };

void heapify(int* a) {
	for (int i = 1; i < size; i++) {
		int c = i;
		do {
			int par = (c - 1) / 2;
			if (a[par] < a[c]) {
				int tem = a[par];
				a[par] = a[c];
				a[c] = tem;
			}
			c = par;
		} while (c != 0);
	}
}

void heapSort(int* a) {
	heapify(a);

	for (int i = size - 1; i >= 0; i--) {
		int tem = a[0];
		a[0] = a[i];
		a[i] = tem;
		int par = 0;
		int c = 1;

		do {
			c = 2 * par + 1;

			if (c < i - 1 && a[c] < a[c + 1]) {
				c++;
			}

			if (c < i && a[par] < a[c]) {
				tem = a[par];
				a[par] = a[c];
				a[c] = tem;
			}
			par = c;
		} while (c < i);
	}
}

int main() {
	
	heapSort(arr);

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}

#endif
