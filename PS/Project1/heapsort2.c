#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int size = 10;
int arr[10] = { 20, 1, 21, 6, 6, 5, 15, 7, 2, 32 };

void heapify(int* a, int size) {
	for (int i = size/2; i >=0; i--) {

		int par = i;
		int ch = (i*2)+1;

		while (ch <= size-1) {
			if ((ch<size-1) &&(a[ch] < a[ch + 1])) {
				ch++;
			}
			if (a[par] < a[ch]) {
				int temp = a[par];
				a[par] = a[ch];
				a[ch] = temp;
			}
			par = ch;
			ch = (par*2)+1;
		}

	}
}

void heapSort(int *a, int size) {
	heapify(a, size);
	int tem;
	int ch, par;
	for (int i = size-1; i >0; i--) {
		int tem = a[i];
		a[i] = a[0];
		a[0] = tem;
		par = 0;
		ch = (par * 2) + 1;

		while (ch <= i-1) {
			if ((ch <i-1) && (a[ch] < a[ch + 1])) {
				ch++;
			}
			if (tem < a[ch]) {
				a[par] = tem;
				a[par] = a[ch];
				a[ch] = tem;
			}
			par = ch;
			ch = (par * 2) + 1;
		}
	}
}


int main() {
	heapSort(arr, size);


	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}
#endif