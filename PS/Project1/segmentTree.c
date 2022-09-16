
#if 0
#include <stdio.h>
#include <stdlib.h>


int segtree[1000];
int N, H; A;

int nodes[10] = { 5,4,3,8,7,9,11,15,22,6 };


int seginit(int tree[], int s, int e, int n) {

	if (s == e) {
		tree[n] = nodes[s];
		return tree[n];
	}
	else {
		return tree[n] = seginit(tree, s, (s + e) / 2, (n * 2) + 1) + seginit(tree, (s + e) / 2 + 1, e, n * 2 + 2);
	}
}

int segsum(int tree[],  int le, int ri, int s, int e, int n) {
	if (ri < s || le > e) return 0;
	if (le <= s && e <= ri) return tree[n];
	int a = segsum(tree, le, ri, s, (s + e) / 2, n * 2 + 1);
	int b = segsum(tree, le, ri, (s + e) / 2 + 1, e, n * 2 + 2);
	return  a + b;
}

void segmod(int tree[], int s, int e, int n, int idx, int diff) {
	if (idx < s || e < idx) return;
	tree[n] = tree[n] + diff;
	if (s == e) return;
	segmod(tree, s, (s + e) / 2, n * 2 + 1, idx, diff);
	segmod(tree, (s + e) / 2 + 1, e,n * 2 + 2, idx, diff);
}

int main() {
	seginit(segtree, 0, 9, 0);
	
	printf("2~5 sum: %d\n", segsum(segtree, 2, 5, 0,9,0));

	int idx = 3;
	int change = 15;
	printf("arr[3] : 8 -> 15\n");
	segmod(segtree, 0, 9, 0, idx, change - nodes[idx]);
	nodes[idx] = change;
	printf("2~5 sum: %d", segsum(segtree, 2, 5, 0, 9, 0));
	return 0;
}
#endif