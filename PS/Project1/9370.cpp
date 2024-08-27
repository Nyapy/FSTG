#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 987654321

int n, m, t, T;
int s, g, h;
int a, b, d;

typedef struct path {
	int st, des, dist;
	bool passed;
	path* next;
}path;

typedef struct path_vector {
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

path doro[100001];
path_vector doroVector[2001];

int visited[2001];
bool ghPassed[2001];
bool candi[2001];

typedef struct priority {
	int size;
	path* data[100001];

	void push(int st,int dest, int dist, bool passed) {
		path* tem = (path*)malloc(sizeof(path));
		tem->st = st;
		tem->des = dest;
		tem->dist = dist;
		tem->passed = passed;
		int ch = ++size;

		while (ch > 1 && data[ch / 2]->dist > tem->dist) {
			data[ch] = data[ch / 2];
			ch /= 2;
		}
		data[ch] = tem;
	}

	path pop() {
		path ret = *data[1];
		path* tem = data[size--];
		int par = 1;
		int ch = 2;

		while (ch <= size) {
			if (ch < size && data[ch]->dist > data[ch + 1]->dist) ch++;
			if (data[ch]->dist > tem->dist) break;
			data[par] = data[ch];
			par = ch;
			ch *= 2;
		}
		data[par] = tem;
		return ret;
	}

	void clear() {
		while (size) pop();
	}

};

priority q;

void dijk() {

	q.push(0,s, 0, false);

	while (q.size) {
		path tn = q.pop();
		if (visited[tn.des] < tn.dist) continue;
		if (visited[tn.des] == tn.dist) {
			if (ghPassed[tn.st] || tn.passed) ghPassed[tn.des] = true;
			continue;
		}
		if (ghPassed[tn.st] || tn.passed) ghPassed[tn.des] = true;
		visited[tn.des] = tn.dist;

		path* next = doroVector[tn.des].head;
		for (int i = 0; i < doroVector[tn.des].size; i++) {
			q.push(tn.des, next->des, next->dist + tn.dist, next->passed || ghPassed[tn.st]);
			next = next->next;
		}

	}

}


int main() {

	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++) {
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);

		for (int i = 1; i <= n; i++) {
			doroVector[i].size = 0;
			visited[i] = INF;
			ghPassed[i] = false;
			candi[i] = false;
		}


		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &d);
			doro[i].st = a;
			doro[i].des = b;
			doro[i].dist = d;
			doro[i].passed = false;
			doroVector[a].push(&doro[i]);
			doro[i + m].st = b;
			doro[i + m].des = a;
			doro[i + m].dist = d;
			doro[i + m].passed = false;
			doroVector[b].push(&doro[i + m]);
			if ((g == a && h == b) || (g == b && h == a)) {
				doro[i].passed = true;
				doro[i + m].passed = true;
			}

		}

		for (int i = 0; i < t; i++) {
			scanf("%d", &a);
			candi[a] = true;
		}


		dijk();
		q.clear();
		for (int i = 1; i <= n; i++) {
			if (ghPassed[i] && candi[i]) printf("%d ", i);
		}
		printf("\n");


	}


	return 0;
}

#endif