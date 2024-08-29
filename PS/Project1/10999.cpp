#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long tree[4000001];
int N, M, K;
long long lazy[4000001];
int a, b, c;
long long d;

long long makeSegtree(int node, int start, int end) {
	if (start == end) {
		scanf("%lld", &tree[node]);
		return tree[node];
	}

	long long a = makeSegtree(node * 2, start, (start + end) / 2);
	long long b = makeSegtree(node * 2 + 1, (start + end) / 2 + 1, end);
	return tree[node] = a + b;
}

long long update(int node, int start, int end, int left, int right, long long mod) {
	if (lazy[node]) {
		tree[node] += (lazy[node] * (end - start + 1));
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (end < left || start > right) return tree[node];
	if (left <= start && end <= right) {
		tree[node] += (mod * (end - start + 1));
		if (start != end) {
			lazy[node * 2] += mod;
			lazy[node * 2 + 1] += mod;
		}
		return tree[node];
	}

	long long a = update(node * 2, start, (start + end) / 2, left, right, mod);
	long long b = update(node * 2+1, (start + end) / 2+1, end, left, right, mod);
	
	return tree[node] = a + b;
}

long long rangeSum(int node, int start, int end, int left, int right) {
	if (lazy[node]) {
		tree[node] += (lazy[node] * (end-start+1));
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (end < left || start > right) return 0;
	if (left <= start && end <= right) {
		return tree[node];
	}
	long long a = rangeSum(node * 2, start, (start + end) / 2, left, right);
	long long b = rangeSum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return a + b;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	makeSegtree(1, 0, N - 1);

	for (int i = 0; i < M+K; i++) {
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %d %lld", &b, &c, &d);
			update(1, 0, N - 1, b - 1, c - 1, d);

		}
		else {
			scanf("%d %d", &b, &c);
			printf("%lld\n", rangeSum(1, 0, N - 1, b - 1, c - 1));
		}
	}

	return 0;
}

#endif
