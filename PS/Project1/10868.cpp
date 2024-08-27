#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 1000000001
int N, M;
int segTree[300000];
int l, r;

int small(int a, int b) {
	return a < b ? a : b;
}

void makeTree(int node, int start, int end) {
	if (start == end) {
		scanf("%d", &segTree[node]);
		return ;
	}

	makeTree(node * 2, start, (start + end) / 2);
	makeTree(node * 2 + 1, (start + end) / 2 + 1, end);
	segTree[node] = small(segTree[node*2], segTree[node * 2+1]);
}

int find(int node, int start, int end, int left, int right) {
	if (right < start || left > end) return INF;
	
	if (start >= left && right >= end) return segTree[node];

	int a = find(node * 2, start, (start + end) / 2, left, right);

	int b = find(node * 2+1, (start + end) / 2+1, end, left, right);
	return small(a, b);
}

int main() {

	scanf("%d %d", &N, &M);
	makeTree(1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &l, &r);
		printf("%d\n", find(1,0,N-1,l - 1, r - 1));
	}

	return 0;
}

#endif
