#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, M, X, s,e,t;

typedef struct vnode {
	int city, time;
	struct vnode* next;
}vn;

typedef struct Vector {
	vn* first,* last;
	int size;
}vector;

void addVector(vector* v,int num, int time) {
	vn* nv = (vn*)malloc(sizeof(vn));
	nv->city = num, nv->time= time;
	if (v->size == 0) {
		v->first = nv;
		v->first->next = nv;
	}
	else {
		v->last->next = nv;
	}
	v->last = nv;
	v->size++;
}

vector back[1001], go[1001];
int dist_go[1001], dist_back[1001];


typedef struct hnode {
	int dist, city;
}hn;

//Èü Å©±â¸¦ ³·Ãçµµ µÇ´Â°¡?
typedef struct HEAP {
	hn* heap[5001];
	int size;
}h;

void hpush(h* heap,int dist, int city) {
	int i;
	i = ++(heap->size);
	hn* nh = (hn*)malloc(sizeof(hn));
	nh->city = city, nh->dist = dist;
	while ((i != 1) && (nh->dist < heap->heap[i / 2]->dist)) {
		heap->heap[i] = heap->heap[i / 2];
		i /= 2;
	}
	heap->heap[i] = nh;
}

hn* hpop(h* heap) {
	int parent=1, child=2;
	hn* ret = heap->heap[1], *tem = heap->heap[heap->size--];

	while (child <= (heap->size)) {
		if ((child < heap->size)&& ((heap->heap[child]->dist) > (heap->heap[child+1]->dist))) {
			child++;
		}
		if (tem->dist <= heap->heap[child]->dist) break;

		heap->heap[parent] = heap->heap[child];
		parent = child;
		child *= 2;
	}
	heap->heap[parent] = tem;
	return ret;
}

int main() {
	
	scanf("%d %d %d", &N, &M, &X);
	for (int i = 1; i <= N; i++) {
		dist_go[i] = 1000000;
		dist_back[i] = 1000000;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s,&e,&t);
		addVector(&back[s], e, t);
		addVector(&go[e], s, t);
	}

	h pq;
	pq.size = 0;

	hpush(&pq, 0, X);
	int time, city;
	hn* tem;
	vn *tv;
	while (pq.size) {
		tem = hpop(&pq);
		time = tem->dist, city = tem->city;
		if (dist_go[tem->city] != 1000000) continue;
		dist_go[tem->city] = tem->dist;
		
		tv = go[city].first;
		for (int i = 0; i < go[city].size; i++) {
			if (dist_go[tv->city] > time + tv->time) hpush(&pq, time + tv->time, tv->city);
			tv = tv->next;
		}
	}

	hpush(&pq, 0, X);
	while (pq.size) {
		tem = hpop(&pq);
		time = tem->dist, city = tem->city;
		if (dist_back[tem->city] != 1000000) continue;
		dist_back[tem->city] = tem->dist;

		tv = back[city].first;
		for (int i = 0; i < back[city].size; i++) {
			if (dist_back[tv->city] > time + tv->time) hpush(&pq, time + tv->time, tv->city);
			tv = tv->next;
		}
	}
	int ans=0;
	for (int i = 1; i < N + 1; i++) {
		if (ans < dist_go[i] + dist_back[i]) {
			ans = dist_go[i] + dist_back[i];
		}
	}

	printf("%d", ans);
	return 0;
}

#endif
