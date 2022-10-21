
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int lower_bound(int *a, int find, int n) {
	int s = 0;
	int e = n-1;

	while (s < e) {
		int mid = (s + e) / 2;
		
		if (a[mid] >= find) e = mid;
		else {
			s = mid + 1;
		}
	}
	return s;
}

int upper_bound(int* a, int find, int n) {
	int s = 0;
	int e = n - 1;

	while (s < e) {
		int mid = (s + e) / 2;
		if (a[mid] <= find) s = mid+1;
		else e = mid;
	}
}

int a[10] = {1 ,3,5,7,9,9,13,15,17,19};

int main() {
	int lower = lower_bound(a, 9, 20);
	int upper = upper_bound(a, 9, 10);
	printf("a[%d] : %d\n", lower, a[lower]);
	printf("a[%d] : %d", upper, a[upper]);
	return 0;
}

#endif
