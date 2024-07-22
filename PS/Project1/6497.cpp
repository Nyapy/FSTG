#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, m, x, y, z;

int par[200001];

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void unionFind(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) par[b] = a;
	else par[a] = b;
}

bool isGroup(int a, int b) {
	a = find(a);
	b = find(b);
	return a == b ? 1 : 0;
}

typedef struct path {
	int a, b, v;
};

path road[200000];

typedef struct pq {
	int size;
	path* data[200001];

	void push(path* a) {
		int ch = ++size;

		while (ch > 1 && data[ch / 2]->v > a->v) {
			data[ch] = data[ch / 2];
			ch /= 2;
		}
		data[ch] = a;
	}

	path* pop() {
		path* ret = data[1];
		path* tem = data[size--];
		int ch = 2, par = 1;

		while (ch <= size) {
			if (data[ch]->v > data[ch + 1]->v) ch++;
			if (data[ch]->v > tem->v) break;
			data[par] = data[ch];
			par = ch;
			ch *= 2;
		}
		data[par] = tem;
		return ret;
	}
};

pq q;
int main() {

	while (1) {
		scanf("%d %d", &m, &n);
		if (!m && !n) break;
		int ans = 0;
		int cnt = 0;
		q.size = 0;
		for (int i = 0; i < m; i++) {
			par[i] = i;
		}

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			road[i].a = x;
			road[i].b = y;
			road[i].v = z;
			q.push(&road[i]);
		}

		while (cnt < m - 1) {
			path* tem = q.pop();
			if (isGroup(tem->a, tem->b)) {
				ans += tem->v;
				continue;
			}
			unionFind(tem->a, tem->b);
			cnt++;
		}

		while (q.size) {
			path* tem = q.pop();
			ans += tem->v;
		}
		printf("%d\n", ans);

	}
	return 0;
}

#endif