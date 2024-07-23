#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, M;
int A, B, C;
typedef struct br {
	int a, b, w;
};

int small(int a, int b, int c) {
	int tem;
	tem = a < b ? a : b;
	tem = tem < c ? tem : c;
	return tem;
}

br bridge[100001];
br copy[100001];

int par[100001];
int weight[100001];

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void unionFind(int a, int b) {
	a = find(a);
	b = find(b);
	if (weight[a] < weight[b]) par[b] = a;
	else par[a] = b;
}

bool isGroup(int a, int b) {
	a = find(a);
	b = find(b);
	return a == b ? 1 : 0;
}

int from, to;

void merge(int l, int r) {
	int mid = (l + r) / 2;
	int i = l, j = mid + 1, k = l;

	while (i <= mid && j <= r) {
		if (bridge[i].w > bridge[j].w) copy[k++] = bridge[i++];
		else copy[k++] = bridge[j++];
	}
	while (i <= mid) copy[k++] = bridge[i++];
	while (j <= r) copy[k++] = bridge[j++];

	for (k = l; k <= r; k++) {
		bridge[k] = copy[k];
	}
}

void mergeSort(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;

	mergeSort(l, mid);
	mergeSort(mid + 1, r);

	merge(l, r);

}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		bridge[i].a = A;
		bridge[i].b = B;
		bridge[i].w = C;
	}
	scanf("%d %d", &from, &to);

	for (int i = 1; i <= N; i++) {
		par[i] = i;
		weight[i] = 1000000001;
	}
	mergeSort(0, M - 1);
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		if (isGroup(from, to)) break;
		if (cnt == N - 1) break;
		if (isGroup(bridge[i].a, bridge[i].b)) continue;
		weight[bridge[i].a] = bridge[i].w;
		weight[bridge[i].b] = bridge[i].w;

		cnt++;
		unionFind(bridge[i].a, bridge[i].b);
	}

	printf("%d", weight[find(from)]);
}

#endif