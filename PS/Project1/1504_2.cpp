#if 0
¹Ì¿Ï.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, E, a, b, c, v1, v2, dist, node;

typedef struct vnode {
	int num, dist;
	struct vnode* next;
}vn;

typedef struct VEC {
	vn* first, * last;
	int size;
}vector;

vector adj[801];

int dist1[801], dist2[801];

void addV(vector* vec, int num, int dist) {
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
	hn* heap[100001];
}heapq;

heapq pq;

void heappush(heapq* heap, int num, int dist) {
	int i = ++(heap->size);
	hn* nn = (hn*)malloc(sizeof(hn));
	nn->dist = dist;
	nn->num = num;

	while ((i != 1) && (heap->heap[i / 2]->dist > nn->dist)) {
		heap->heap[i] = heap->heap[i / 2];
		i /= 2;
	}
	heap->heap[i] = nn;
}

hn* heappop(heapq* heap) {
	int parent = 1, child = 2;
	hn* ret = heap->heap[1];
	hn* tem = heap->heap[(heap->size)--];

	while (child <= heap->size) {
		if ((child < heap->size) && (heap->heap[child] > heap->heap[child + 1])) child++;

		if (tem->dist <= heap->heap[child]->dist) break;

		heap->heap[parent] = heap->heap[child];
		parent = child;
		child *= 2;
	}
	heap->heap[parent] = tem;
	return ret;
}
int visited[801];

int minv(int a, int b) {
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

	pq.size = 0;
	heappush(&pq, v1, 0);
	dist1[v1] = 0;
	while (pq.size) {
		hn* tem = heappop(&pq);
		dist = tem->dist, node = tem->num;
		free(tem);
		if (visited[node] == 1) continue;
		visited[node] = 1;

		vn* tvn = adj[node].first;
		for (int i = 0; i < adj[node].size; i++) {
			if (dist1[tvn->num] > (tvn->dist) + dist) {
				dist1[tvn->num] = (tvn->dist) + dist;
				heappush(&pq, tvn->num, tvn->dist + dist);
			}
			tvn = tvn->next;
		}
	}

	heappush(&pq, v2, 0);
	for (int i = 0; i < N + 1; i++) {
		visited[i] = 0;
	}
	dist2[v2] = 0;

	while (pq.size) {
		hn* tem = heappop(&pq);
		dist = tem->dist, node = tem->num;
		free(tem);
		if (visited[node] == 1) continue;
		visited[node] = 1;

		vn* tvn = adj[node].first;
		for (int i = 0; i < adj[node].size; i++) {
			if (dist2[tvn->num] > (tvn->dist) + dist) {
				dist2[tvn->num] = (tvn->dist) + dist;
				heappush(&pq, tvn->num, tvn->dist + dist);
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
		printf("%d", minv(ans, ans2));
	}
	return 0;
}

#endif