#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int N, M, t;
typedef struct path {
	int from, to, price;
};

path p[30001];
int par[10001];

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void unionFind(int a , int b) {
	a = find(a);
	b = find(b);
	if (a < b)par[b] = a;
	else par[a] = b;
}

bool isGroup(int a,int b) {
	a = find(a);
	b = find(b);
	return a == b ? 1 : 0;
}

typedef struct pq {
	int size;
	path* data[30001];

	void push(path* a) {
		int ch = ++size;

		while (ch > 1 && data[ch / 2]->price > a->price) {
			data[ch] = data[ch / 2];
			ch /= 2;
		}
		data[ch] = a;
	}

	path* pop() {
		path* ret = data[1];
		path* tem = data[size--];
		int par = 1, ch = 2;
		while (ch <= size) {
			if (ch < size && data[ch]->price > data[ch + 1]->price) ch++;
			if (data[ch]->price > tem->price) break;
			data[par] = data[ch];
			par = ch;
			ch *= 2;
		}
		data[par] = tem;
		return ret;
	}
};
int A, B, C;
pq q;
int cnt= 0;
int ans=0;
int main() {
	scanf("%d %d %d", &N, &M, &t);
	for (int i = 1; i <= N; i++) {
		par[i] = i;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		p[i].from = A;
		p[i].to = B;
		p[i].price = C;
		q.push(&p[i]);
	}

	while (cnt < N - 1) {
		path* tem = q.pop();
		if (isGroup(tem->from, tem->to)) continue;
		unionFind(tem->from, tem->to);
		ans += tem->price + cnt * t;
		cnt++;
	}

	printf("%d", ans);
	return 0;
}

#endif