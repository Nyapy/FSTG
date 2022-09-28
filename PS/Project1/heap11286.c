#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct HEAP {
	int nums[100001];
	int size;
}heap;


int abs(int a) {
	if (a < 0) return -1 * a;
	return a;
}

void addHeap(heap *pq, int data) {
	int ch = ++(pq->size);


	while ((ch != 1) && (abs(pq->nums[ch/2]) >= abs(data))) {

		if (abs(pq->nums[ch / 2]) == abs(data)) {
			if (pq->nums[ch / 2] < data) break;
		}
		pq->nums[ch] = pq->nums[ch / 2];
		ch /= 2;
	}
	pq->nums[ch] = data;
}

int popHeap(heap* pq) {

	if (pq->size == 0) return 0;
	int ch = 2, par = 1;

	int ret = pq->nums[1];
	int tem = pq->nums[(pq->size)--];
	
	while (ch <= pq->size) {

		if (ch < pq->size) {
			if (abs(pq->nums[ch]) > abs(pq->nums[ch + 1])) ch++;
			else if (abs(pq->nums[ch]) == abs(pq->nums[ch + 1])) {
				if (pq->nums[ch] > pq->nums[ch + 1]) ch++;
			}
		}

		if (abs(pq->nums[ch]) > abs(tem)) break;
		if (abs(pq->nums[ch]) == abs(tem)) {
			if (pq->nums[ch] >= tem) break;
		}

		pq->nums[par] = pq->nums[ch];

		par = ch;
		ch *= 2;
	}

	pq->nums[par] = tem;

	return ret;
}

int N, x;
int main() {

	scanf("%d", &N);

	heap pq;
	pq.size = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);

		if (x) addHeap(&pq, x);
		else printf("%d\n", popHeap(&pq));
	}

	return 0;
}

#endif
