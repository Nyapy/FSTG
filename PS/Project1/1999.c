#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arr[251][251], N,B,K, I,J;
int tree[251][1024][2];

int xans, nans;

int *inittree(int tree[][1024][2], int s, int e, int n, int arr[][251], int row) {
	if (s == e) {
		tree[row][n][0] = arr[row][s];
		tree[row][n][1] = arr[row][s];
		return tree[row][n];
	}
	int *a = inittree(tree, s, (s + e) / 2, n * 2, arr, row);
	int *b = inittree(tree, (s + e) / 2 + 1, e, n * 2 + 1, arr, row);

	if (a[0] >= b[0]) { tree[row][n][0] = a[0]; }
	else { tree[row][n][0] = b[0]; } 
	if (a[1] >= b[1]) { tree[row][n][1] = b[1]; }
	else { tree[row][n][1] = a[1]; }

	return tree[row][n];
}

void print(int tree[][1024][2], int s, int e, int n, int arr[][251], int row) {
	printf("t[%d] = %d, %d ", n, tree[row][n][0], tree[row][n][1]);
	if (s == e) {
		return;
	}
	print(tree, s, (s + e) / 2, n * 2, arr, row);
	print(tree, (s + e)/2 + 1, e, n * 2 + 1, arr, row);
	printf("\n");
	return;
}

int* minmax(int tree[][1024][2], int n, int s, int e, int le, int ri, int row) {
	int* tem = (int*)malloc(sizeof(int) * 2);
	tem[0] = -1, tem[1] = 256;
	if (ri <s || le >e) {
		
		return tem;
	}
	if (le <= s && e <= ri) {
		tem[0] = tree[row][n][0], tem[1] = tree[row][n][1];
		return tem;
	}

	int* a = minmax(tree, n * 2, s, (s + e) / 2, le, ri, row);
	int* b = minmax(tree, n * 2 + 1, (s + e) / 2 + 1, e, le, ri, row);
	//tem[0] =max(a[0],b[0]), tem[1]= min(a[1], b[1]);
	if (a[0] >= b[0]) { tem[0] = a[0]; }
	else { tem[0] = b[0]; }
	if (a[1] >= b[1]) { tem[1] = b[1]; }
	else { tem[1] = a[1]; }
	free(a), free(b);
	return tem;

}

int main() {

	scanf(" %d %d %d", &N, &B, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf(" %d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		inittree(tree, 1, N, 1, arr, i);
	}

	
	int *tem;
	for (int i = 0; i < K; i++) {
		scanf(" %d %d", &I, &J);
		xans = -1, nans = 251;
		for (int j = I; j < I + B; j++) {
			//print(tree, 1, N, 1, arr, j);
			tem = minmax(tree, 1, 1, N, J, J + B - 1, j);
			//printf("%d %d\n", tem[0], tem[1]);
			if (xans < tem[0]) {
				xans = tem[0];
			}
			if (nans > tem[1]) {
				nans = tem[1];
			}
		}
	}
	printf("%d", xans - nans);
	return 0;
}
#endif