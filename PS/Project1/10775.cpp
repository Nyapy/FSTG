#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int G, P, g;
int par[100000];

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void funion(int a, int b){
	a = find(a);
	b = find(b);
	if (a < b) par[b] = a;
	else par[a] = b;
}

int main() {
	scanf("%d", &G);
	scanf("%d", &P);
	for (int i = 1; i <= G; i++) {
		par[i] = i;
	}
	int ans = 0;
	for (int i = 0; i < P; i++) {
		scanf("%d", &g);
		if (!find(par[g])) break;
		ans++;
		funion(find(g)-1, find(g) );
	}
	printf("%d", ans);
}

#endif