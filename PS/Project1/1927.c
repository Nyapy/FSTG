#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ll long long

typedef struct Minheap {
	int size;
	ll num[100001];
}heap;

void addheap(heap* pq, int data) {
	int ch = ++(pq->size);

	while ((ch != 1) && (pq->num[ch / 2] > data)) {
		pq->num[ch] = pq->num[ch/2];
		ch /= 2;
	}
	pq->num[ch] = data;
}

ll popheap(heap* pq) {

	if (pq->size == 0) return 0;
	int par = 1, ch = 2;
	ll ret = pq->num[1];
	ll tem = pq->num[(pq->size)--];

	while (ch <= pq->size) {
		if ((ch < pq->size) && (pq->num[ch + 1] < pq->num[ch])) {
			ch++;
		}

		if (pq->num[ch] >= tem) break;

		pq->num[par] = pq->num[ch];
		par = ch;
		ch *= 2;
	}
	pq->num[par] = tem;
	return ret;
}

int N, x, ans;

int main() {

	heap pq;
	pq.size = 0;
	for (int i = 0; i < 100001; i++) {
		pq.num[i] = (1<<32);
	}


	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		if (x) addheap(&pq, x);
		else printf("%d\n", popheap(&pq));
	}

	return 0;
}

#endif
