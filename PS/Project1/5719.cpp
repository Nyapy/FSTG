#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 987654321
int N, M, U, V, P, S, D;

typedef struct path {
	int s, d, dist, num;
	bool used;
	path* next;
}path;

typedef struct vector {
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
	};
}vector;

typedef struct traceNode {
	int v;
	traceNode* next;
}tr;

typedef struct Tvector {
	int size;
	tr* head, * tail;

	void push(int v) {
		tr* tem = (tr*)malloc(sizeof(tr));
		tem->v = v;
		if (size++) {
			tail->next = tem;
		}
		else {
			head = tem;
		}
		tail = tem;
	};
	void clear() {
		while (size) {
			tr* el = head;
			head = head->next;
			free(el);
			size--;
		}
	}

};

path pathInfo[10001];
vector pathNode[501];

Tvector route[500];
int visited[500];

typedef struct priority {
	int size;
	path* data[10001];

	void push(int s, int d, int dist, int num) {
		path* tem = (path*)malloc(sizeof(path));
		tem->s = s;
		tem->d = d;
		tem->dist = dist;
		tem->num = num;
		int ch = ++size;
		while (ch > 1 && tem->dist < data[ch / 2]->dist) {
			data[ch] = data[ch / 2];
			ch /= 2;
		}
		data[ch] = tem;
	}

	path pop() {
		path ret = *data[1];
		free(data[1]);
		path* tem = data[size--];
		int par = 1; int ch = 2;

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

	void clear() {
		while (size) {
			pop();
		}
	}

};
bool tvisited[500];
priority pq;

void eliPath(int num) {
	if (num == S) return;
	if (tvisited[num]) return;
	tvisited[num] = true;
	tr* tem = route[num].head;
	for (int i = 0; i < route[num].size; i++) {
		pathInfo[tem->v].used = true;
		eliPath(pathInfo[tem->v].s);
		tem = tem->next;
	}


}

void dijk(int st, int ed, int second) {

	pq.push(500, st, 0, 10000);

	while (pq.size) {
		path tn = pq.pop();
		if (visited[tn.d] < tn.dist) continue;

		if (visited[tn.d] == tn.dist && !second) {
			if (!second) route[tn.d].push(tn.num);
			continue;
		};

		if (visited[D] < tn.dist) {
			break;
		}

		visited[tn.d] = tn.dist;
		if (!second) route[tn.d].push(tn.num);

		path* nn = pathNode[tn.d].head;
		for (int i = 0; i < pathNode[tn.d].size; i++) {
			if (second && nn->used) {
				nn = nn->next;
				continue;
			}
			if (nn->dist + tn.dist >= visited[nn->d]) {
				nn = nn->next;
				continue;
			}
			pq.push(nn->s, nn->d, nn->dist + tn.dist, nn->num);
			nn = nn->next;
		}

	}
	if(!second) eliPath(D);
	pq.clear();
	return;

}

int main() {

	//freopen("almost.in", "r", stdin);
	while (1) {
		scanf("%d %d", &N, &M);
		if (!N && !M) break;
		scanf("%d %d", &S, &D);
		for (int i = 0; i < N; i++) {
			visited[i] = INF;
			route[i].clear();
			pathNode[i].size = 0;
			tvisited[i] = false;

		}
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &U, &V, &P);
			pathInfo[i].s = U;
			pathInfo[i].d = V;
			pathInfo[i].dist = P;
			pathInfo[i].num = i;
			pathInfo[i].used = false;
			pathNode[U].push(&pathInfo[i]);
		}

		dijk(S, D, false);
		for (int i = 0; i < N; i++) {
			visited[i] = INF;
		}
		dijk(S, D, true);

		if (visited[D] == INF) printf("-1\n");
		else printf("%d\n", visited[D]);

	}

	return 0;
}

#endif