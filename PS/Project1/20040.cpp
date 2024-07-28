#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int par[500000];
int n, m, a, b;

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void unfind(int a, int b) {
	a = find(a);
	b = find(b);
	par[b] = a;
}

bool isCycle(int a, int b) {
	a = find(a);
	b = find(b);
	return a == b ? 1 : 0;
}

int main() {
	scanf("%d %d", &n, &m);
	int ans = 0;
	for (int i = 1; i < n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (isCycle(a, b)) {
			ans = i+1;
			break;
		}
		unfind(a, b);
	}
	printf("%d", ans);

}
#endif