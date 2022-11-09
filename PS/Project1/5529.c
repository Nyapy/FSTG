#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Vnode {
	int val;
	int seq;
	struct Vector* next;
}vn;

typedef struct Vector {
	vn* first, *last;

	int size;
}vector;

void initV(vector *v) {
	v->last = NULL;
	v->size = 0;
}

void addV(int num, int se, vector* v) {
	vn* newV = (vn*)malloc(sizeof(vn));
	newV->val = num;
	newV->seq = se;
	newV->next = NULL;

	if (v->size == 0) {
		v->first = newV;
	}
	else {
		v->last->next = newV;
	}
	v->last = newV;
	v->size++;
}

typedef struct Node {
	long long dist;
	int x, y, xy;
}node;

typedef struct Heap {
	node heap[200001];
	int size;
}heap;

heap* init(heap* h) {
	h->size = 0;
	return h;
}

void addHeap(heap* h, node n) {
	int i;
	i = ++(h->size);

	while ((i != 1) && (n.dist > h->heap[i / 2].dist)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = n;
}

node popHeap(heap* h) {
	int parent, child;
	node ret, tem;

	ret = h->heap[1];
	tem = h->heap[(h->size--)];
	parent = 1;
	child = 2;

	while (child <= h->size) {
		if ((child < h->size) && ((h->heap[child].dist) < h->heap[child + 1].dist)) {
			child++;
		}

		if (tem.dist >= h->heap[child].dist) break;

		h->heap[parent] = h->heap[child];

		parent = child;
		child *= 2;
	}
	h->heap[parent] = tem;

	return ret;
}

int M, N, K;
vector xsw[100005], ysw[100005];
vn *temv;
long long visited[200001][2];
heap pq;
int x, y,xy,di;
long long dist;

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

FILE* fp;

int main() {
	scanf("%d %d %d", &M,&N,&K);
	for (int i = 0; i <= K; i++) {
		visited[i][0] = 99999999999;
		visited[i][1] = 99999999999;
	}
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &x, &y);
		addV(y, i, &xsw[x]);
		addV(x, i, &ysw[y]);
	}

	init(&pq);
	node tem;
	tem.dist = 0;
	tem.x = 1, tem.y = 1, tem.xy = 1;
	
	addHeap(&pq, tem);

	long long ans=0;

	if (!xsw[M].size && !ysw[N].size) {
		pq.size = 0;
	}

	addV(N, K, &xsw[M]);
	addV(M, K, &ysw[N]);

	while (pq.size) {
		tem = popHeap(&pq);
		di = tem.dist, x = tem.x, y = tem.y, xy = tem.xy;

		if ((x == M) && (y == N)) {
			ans = di;
			break;
		}

		if (xy) {
			temv = xsw[x].first;
			for (int i = 0; i < xsw[x].size; i++) {
				dist = di + abs(y - (temv->val)) + 1;
				if (visited[temv->seq][0] > dist) {
					visited[temv->seq][0] = dist;
					node t;
					t.dist = dist, t.x = x, t.y = temv->val, t.xy = 0;
					addHeap(&pq,t);
				}
				temv = temv->next;
			}
		}
		else {
			temv = ysw[y].first;
			for (int i = 0; i < ysw[y].size; i++) {
				dist = di + abs(x - (temv->val)) + 1;
				if (visited[temv->seq][1] > dist) {
					visited[temv->seq][1] = dist;
					node t;
					t.dist = dist, t.x = temv->val, t.y = y, t.xy = 1;
					addHeap(&pq, t);
				}
				temv = temv->next;
			}
		}

	}

	printf("%lld", ans - 1);

	return 0;
}

#endif
