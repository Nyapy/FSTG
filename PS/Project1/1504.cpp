#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;
int N, E, a, b, c, v1, v2, dist, node;

typedef struct vnode {
	int num, dist;
	struct vnode* next;
}vn;

typedef struct VEC {
	vn* first, * last;
	int size;
}vect;

vect adj[801];

int dist1[801], dist2[801];

void addV(vect* vec, int num, int dist) {
	vn* nvec = (vn*)malloc(sizeof(vn));
	nvec->num = num;
	nvec->dist = dist;
	if (vec->size == 0) {
		vec->first = nvec;
	}
	else {
		vec->last->next = nvec;
	}
	vec->last = nvec;
	vec->size++;
}

typedef struct hnode {
	int dist, num;
}hn;

typedef struct HEAPQ {
	int size;
	hn* heap[640000];
}heapq;

heapq pq;


int visited[801];

struct cmp {
	bool operator() (hn a, hn b){
		return a.dist > b.dist;
	}
};


int small(int a, int b) {
	if (a < b) return a;
	return b;
}


int main() {

	scanf("%d %d", &N, &E);

	for (int i = 1; i < N + 1; i++) {
		dist1[i] = 987654321;
		dist2[i] = 987654321;
	}

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		addV(&adj[b], a, c);
		addV(&adj[a], b, c);
	}

	scanf("%d %d", &v1, &v2);

	priority_queue<hn, vector<hn>, cmp> pq;

	hn first;
	first.dist = 0;
	first.num = v1;
	pq.push(first);
	dist1[v1] = 0;

	while (!pq.empty()) {
		hn tem = pq.top();
		dist = tem.dist, node = tem.num;
		pq.pop();
		if (visited[node] == 1) continue;
		visited[node] = 1;

		vn* tvn = adj[node].first;
		for (int i = 0; i < adj[node].size; i++) {
			if (dist1[tvn->num] > (tvn->dist) + dist) {
				dist1[tvn->num] = (tvn->dist) + dist;
				hn no;
				no.dist = tvn->dist + dist;
				no.num = tvn->num;
				pq.push(no);
			}
			tvn = tvn->next;
		}
	}

	first.dist = 0;
	first.num = v2;
	pq.push(first);
	for (int i = 0; i < N + 1; i++) {
		visited[i] = 0;
	}
	dist2[v2] = 0;

	while (!pq.empty()) {
		hn tem = pq.top();
		dist = tem.dist, node = tem.num;
		pq.pop();
		if (visited[node] == 1) continue;
		visited[node] = 1;

		vn* tvn = adj[node].first;
		for (int i = 0; i < adj[node].size; i++) {
			if (dist2[tvn->num] > (tvn->dist) + dist) {
				dist2[tvn->num] = (tvn->dist) + dist;
				hn no;
				no.dist = tvn->dist + dist;
				no.num = tvn->num;
				pq.push(no);
			}
			tvn = tvn->next;
		}
	}

	int nodap = 0;

	if (visited[1] == 0 || visited[N] == 0 || visited[v1] == 0) nodap = 1;

	int ans = dist1[1] + dist1[v2] + dist2[N],
		ans2 = dist2[1] + dist2[v1] + dist1[N];

	if (nodap) {
		printf("-1");
	}
	else {
		printf("%d", small(ans, ans2));
	}
	return 0;
}
#endif