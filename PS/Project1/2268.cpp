#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int N, M;
long long tree[4000000];
int a, b, c;
int arr[1000000];
void modify(int node, int start, int end, int num, int k) {

	if (start <= num && num <= end) tree[node] += k;
	else return;
	if (start == end) {
		return;
	}

	modify(node * 2, start, (start + end) / 2, num, k);
	modify(node * 2+1, (start + end) / 2+1, end, num, k);
}

void swap(int* a, int* b) {
	int tem = *b;
	*b = *a;
	*a = tem;
}

long long sum(int node, int start, int end, int left, int right) {
	if (end < left || start > right) return 0;

	if (left <= start && end <= right) return tree[node];

	long long a = sum(node * 2, start, (start + end) / 2, left, right);
	long long b = sum(node * 2+1,(start + end) / 2+1, end, left, right);
	return a + b;
}

int main() {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a) {

			modify(1, 0, N - 1, b-1, c-arr[b-1]);
			arr[b - 1] = c;
		}
		else {
			if (b > c) swap(&b, &c);
			printf("%lld\n", sum(1, 0, N - 1, b-1, c-1));
		}
		
	}

	return 0;
}

#endif
