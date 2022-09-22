#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int num;
	int vote;
}node;

typedef struct PQ {
	node queue[50];
	int size ;
}pq;

void addpq(pq* q, node cand) {
	int ch = ++(q->size);
	q->queue[ch] = cand;

	int par = (ch - 1) / 2;
	node tem;
	while ((ch != 1) && (cand.vote > q->queue[ch/2].vote)) {
		q->queue[ch] = q->queue[ch/2];
		ch /= 2;
	}
	q->queue[ch] = cand;
}

node poppq(pq* q) {
	node ret = q->queue[1];

	node tem = q->queue[(q->size)--];
	int par = 1;
	int ch = 2;
	
	while (ch <= q->size) {
		if ((q->queue[ch].vote < q->queue[ch + 1].vote) &&(ch < q->size)) {
			ch++;
		}

		if (tem.vote >= q->queue[ch].vote) break;

		q->queue[par] = q->queue[ch];

		par = ch;
		ch *= 2;

	}
	q->queue[par] = tem;

	return ret;
}

int N, a, Ob, ans;

int main() {
	pq q;
	node cand;
	q.size = 0;
	for (int i = 0; i < 50; i++) {
		q.queue[i].num = 0;
		q.queue[i].vote = 0;
	}

	scanf(" %d", &N);
	scanf(" %d", &Ob);
	a = 2;

	for (int i = 0; i < N-1; i++) {
		scanf(" %d", &cand.vote);
		cand.num = a++;

		addpq(&q, cand);
	}
	ans = 0;
	while (q.size) {
		cand = poppq(&q);
		if (Ob > cand.vote) break;
		ans++;
		cand.vote--;
		Ob++;
		addpq(&q, cand);
	}
	printf("%d", ans);


	return 0;
}

#endif
