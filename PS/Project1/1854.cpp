#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int n, m, k;
int a, b, c;

typedef struct path {
	int des;
	long long dist;
	path* next;
}path;

path doro[250000];

typedef struct Vector {
	int size;
	path* head, * tail;

	void push(path* tem) {
		if (size++) {
			tail->next = tem;
		}
		else {
			head = tem;
		}
		tail = tem;
	}
};

typedef struct PQ {
	int size;
	path* data[3000001];

	void push(int des, long long dist) {
		path* tem = (path*)malloc(sizeof(path));
		tem->des = des;
		tem->dist = dist;
		int ch = ++size;

		while (ch > 1 && data[ch / 2]->dist > tem->dist) {
			data[ch] = data[ch / 2];
			ch /= 2;
		}
		data[ch] = tem;
	}

	path pop() {
		path ret = *data[1];
		free(data[1]);
		path* tem = data[size--];
		int par = 1;
		int ch = 2;

		while (ch <= size) {
			if (ch <size && data[ch]->dist > data[ch + 1]->dist) ch++;
			if (data[ch]->dist > tem->dist) break;
			data[par] = data[ch];
			par = ch;
			ch *= 2;
		}
		data[par] = tem;

		return ret;
	}
}PQ;

Vector doroVector[1001];

int ks[1001];
long long visited[1001];
PQ q;

void dijk() {
	q.push(1, 0);

	while (q.size) {
		path tn = q.pop();

		if (ks[tn.des] >= k) continue;
		visited[tn.des] = tn.dist;
		ks[tn.des] ++;

		path *next = doroVector[tn.des].head;
		for (int i = 0; i < doroVector[tn.des].size; i++) {
			q.push(next->des, next->dist + tn.dist);
			next= next->next;
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i <= n; i++) {
		visited[i] = -1;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		doro[i].des = b;
		doro[i].dist = c;
		doroVector[a].push(&doro[i]);
	}


	dijk();

	for (int i = 1; i <= n; i++) {
		if (ks[i] == k)printf("%d\n", visited[i]);
		else printf("-1\n");
	}

	return 0;
}

#endif
