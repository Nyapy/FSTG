#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
}node;

typedef struct Heap {
	node heap[100];
	int size;
}heap;

heap* init(heap* h) {
	h = (heap*)malloc(sizeof(heap));
	h->size = 0;
	return h;
}

void addHeap(heap *h, node n) {
	int i;
	i = ++(h->size);

	while ((i != 1) && (n.data > h->heap[i / 2].data)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = n;
}

node popHeap(heap *h) {
	int parent, child;
	node ret, tem;

	ret = h->heap[1];
	tem = h->heap[(h->size--)];
	parent = 1;
	child = 2;

	while (child <= h->size) {
		if ((child < h->size) && ((h->heap[child].data) < h->heap[child + 1].data)) {
			child++;
		}

		if (tem.data >= h->heap[child].data) break;

		h->heap[parent] = h->heap[child];

		parent = child;
		child *= 2;
	}
	h->heap[parent] = tem;

	return ret;
}


int main() {
	heap *h=NULL;
	node a;
	h = init(h);
	a.data = 33;
	addHeap(h, a);
	a.data = 55;
	addHeap(h, a);
	a.data = 11;
	addHeap(h, a);
	a.data = 14;
	addHeap(h, a);
	a.data = 2;
	addHeap(h, a);
	a.data = 77;
	addHeap(h, a);

	while (h->size > 0) {
		a = popHeap(h);
		printf("%d ", a.data);
	}
}

#endif
