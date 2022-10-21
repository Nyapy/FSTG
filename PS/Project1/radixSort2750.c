#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int N;
int arr[2000001];
int now[2000001];
int idx[2000001];
int sorting[10][2000001], msorting[10][2000001];;
int count[11], mcount[10];

int maxj=1, tem;
int pl = 0, ma = 1000000;

void radix(int a[], int N, int mj) {
	for (int i = 10; i <= mj*10; i*=10) {
		//plus
		for (int j = 0; j < pl; j++) {
			tem = now[idx[j]] % 10;
			now[idx[j]] /= 10;
			sorting[tem][count[tem]++] = idx[j];
		}
		int a=0;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < count[j]; k++) {
				idx[a++] = sorting[j][k];
			}
			count[j] = 0;
		}
		//minus
		for (int j = 1000000; j < ma; j++) {
			tem = now[idx[j]] % 10;
			now[idx[j]] /= 10;
			msorting[tem][mcount[tem]++] = idx[j];
		}
		a = 1000000;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < mcount[j]; k++) {
				idx[a++] = msorting[j][k];
			}
			mcount[j] = 0;
		}
	}
}


int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tem);
		if (tem >= 0) {
			arr[pl] = tem;
			now[pl] = tem;
			idx[pl] = pl;
			pl++;
		}
		else{
			tem *= -1;
			arr[ma] = tem;
			now[ma] = tem;
			idx[ma] = ma;
			ma++;
		}
		while (tem/maxj) {
			tem %= maxj;
			maxj*=10;
		}
	}
	radix(arr, N, maxj);

	for (int i = ma-1; i >= 1000000; i--) {
		printf("%d ", -arr[idx[i]]);
	}
	for (int i = 0; i < pl; i++) {
		printf("%d ", arr[idx[i]]);
	}
	return 0;
}

#endif
