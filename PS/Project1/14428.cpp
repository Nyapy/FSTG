#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, M;
int tree[400000];
int arr[100000];
int idx[400000];

int small(int a, int b) {
	return a < b ? a : b;
}

int mod(int node, int start, int end, int v, int num) {
	if (start == end) {
		return tree[node];
	}
	if (start <= num && num <= end) {
		int a = mod(node * 2, start, (start + end) / 2, v, num);
		int b = mod(node * 2 + 1, (start + end) / 2 + 1, end, v, num);
		if (arr[a] < arr[b]) {
			tree[node] = a;
		}
		else if (arr[a] > arr[b]) {
			tree[node] = b;
		}
		else {
			tree[node] = small(a, b);
		}
		return tree[node];
	}
	else return tree[node];
}

int min(int node, int start, int end, int left, int right) {
	if (right < start || left > end) return N;
	if (left <= start && end <= right) return tree[node];

	int a = min(node * 2, start, (start + end) / 2, left, right);
	int b = min(node * 2+1, (start + end) / 2+1, end, left, right);

	if (arr[a] < arr[b]) {
		return a;
	}
	else if(arr[a] > arr[b]){
		return b;
	}
	else {
		return small(a, b);
	}
	return tree[node];
}

int total = 0;

void makeTree(int node, int start, int end) {
	if (start == end) {
		scanf("%d", &arr[total]);
		tree[node] = total;
		total++;
		return;
	}

	makeTree(node * 2, start, (start + end) / 2);
	makeTree(node * 2+1, (start + end) / 2+1, end);
	if (arr[tree[node * 2]] < arr[tree[node * 2 + 1]] ) {
		tree[node] = tree[node * 2];
	}
	else if (arr[tree[node * 2]] > arr[tree[node * 2 + 1]]) {
		tree[node] = tree[node * 2+1];
	}
	else {
		tree[node] = small(tree[node * 2], tree[node * 2 + 1]);
	}
}

int t, a, b;
int main() {
	scanf("%d", &N);
	makeTree(1, 0, N - 1);
	scanf("%d", &M);

	arr[N] = 1000000001;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &t, &a, &b);
		if (t==1) {
			arr[a-1] = b;
			mod(1, 0, N-1, b , a-1);
		}
		else {
			printf("%d\n", min(1, 0, N - 1, a-1, b-1)+1);
		}
	}

	
	return 0;
}


#endif