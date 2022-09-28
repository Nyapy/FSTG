#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
	int data[100000];
	int size ;
}heap;

void addheap(heap* pq, int x) {
	int ch = ++(pq->size);

	while ((ch != 1) && pq->data[ch/2] < x) {
		pq->data[ch] = pq->data[ch / 2];
		ch /= 2;
	}
	pq->data[ch] = x;
}

int popheap(heap* pq ) {

	if (pq->size == 0) {
		return 0;
	}
	int ret = pq->data[1];
	int ch = 2;
	int par = 1;
	int tem = pq->data[(pq->size)--];

	while (ch <= pq->size) {
		if ((ch < pq->size) && (pq->data[ch] < pq->data[ch + 1])) {
			ch++;
		}
		if (tem > pq->data[ch]) break;
		pq->data[par] = pq->data[ch];
		par = ch;
		ch *= 2;
	}
	pq->data[par] = tem;

	return ret;
}

int N,x;



int main() {

	scanf(" %d", &N);


	heap pq;
	pq.size = 0;
	for (int i = 0; i < 100000; i++) {
		pq.data[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		scanf(" %d", &x);
		
		if (x) {
			addheap(&pq, x);
		}
		else {
			printf("%d\n", popheap(&pq));
		}
	}

	return 0;
}

#endif
