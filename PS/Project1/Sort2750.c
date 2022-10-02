#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int size;
int arr[1000000];

void heapify(int* a, int size) {
	for (int i = size / 2; i >= 0; i--) {

		int par = i;
		int ch = (i * 2) + 1;

		while (ch <= size - 1) {
			if ((ch < size - 1) && (a[ch] < a[ch + 1])) {
				ch++;
			}
			if (a[par] < a[ch]) {
				int temp = a[par];
				a[par] = a[ch];
				a[ch] = temp;
			}
			par = ch;
			ch = (par * 2) + 1;
		}

	}
}

void heapSort(int* a, int size) {
	heapify(a, size);
	int tem;
	int ch, par;
	for (int i = size - 1; i > 0; i--) {
		int tem = a[i];
		a[i] = a[0];

		par = 0;
		ch = (par * 2) + 1;

		while (ch <= i - 1) {
			if ((ch < i - 1) && (a[ch] < a[ch + 1])) {
				ch++;
			}
			if (tem >= a[ch]) break;

			a[par] = a[ch];

			par = ch;
			ch = (par * 2) + 1;
		}
		a[par] = tem;
	}
}


int main() {
	
	scanf(" %d", &size);
	for (int i = 0; i < size; i++) {
		scanf(" %d", &arr[i]);
	}

	
	heapSort(arr, size);


	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}
}
#endif