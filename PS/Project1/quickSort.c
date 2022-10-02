#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void quick(int st, int ed, int*a) {
	int pivot = a[(st + ed) / 2];
	int l = st, r = ed;
	int temp;

	while (l <= r) {
		while (a[l] <pivot) l++;
		while (a[r] > pivot) r--;

		if (l <= r) {
			if (l != r) {
				temp = a[l];
				a[l] = a[r];
				a[r] = temp;
			}
			l++;
			r--;
		}
	}

	if (st < r) quick(st, r, a);
	if (l < ed) quick(l, ed, a);

}


int size;
int arr[1000];
int main() {


	scanf(" %d", &size);
	for (int i = 0; i < size; i++) {
		scanf(" %d", &arr[i]);
	}

	quick(0, size - 1, arr);


	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}

#endif

