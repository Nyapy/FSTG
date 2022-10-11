#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Vectornode {
	int num;
	struct Vectornode* front;
}vnode;

typedef struct Vector {
	int size;
	vnode* last;
}vector;

void addVector(int num, vector* vec) {
	vnode* newNode = (vnode*)malloc(sizeof(vnode));
	newNode->num = num;
	newNode->front = vec->last;
	vec->last = newNode;
}

typedef struct Qnode {
	int num;
	struct Qnode* back;
}qnode;

typedef struct Queue {
	int size;
	qnode * front, * tail;
}queue;

void addQ(int num, queue* q) {
	qnode* newNode = (qnode*)malloc(sizeof(qnode));
	newNode->num = num;

	if (q->size == 0) {
		q->front = newNode;
	}
	else {
		q->tail->back = newNode;
	}
	q->tail = newNode;
	(q->size)++;
}

int popQ(queue* q) {
	if (q->size == 0) {
		printf("empty Queue");
		return 0;
	}
	qnode* tem = q->front;
	int ret = tem->num;

	q->front = q->front->back;
	q->size--;
	free(tem);
	return ret;
}


int N,tem;

int times[10001];
int end[10001];
int priority[10001];
vector precon[10001];

queue q;

int main() {
	q.size = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &times[i], &priority[i]);
		precon[i].size = 0;
		precon[i].last = NULL;
		end[i] = 0;
		for (int j = 0; j < priority[i]; j++) {
			scanf(" %d", &tem);
			precon[tem].size++;
			addVector(i, &precon[tem]);
		}

		if (priority[i] == 0) {
			addQ(i, &q);
		}
	}
	int ans = 0;
	while (q.size > 0) {
		int num = popQ(&q);
		end[num] += times[num];
		if (ans < end[num]) {
			ans = end[num];
		}

		int vsize = precon[num].size;
		vnode* vn = precon[num].last;
		for (int i = 0; i < vsize; i++) {

			if (end[vn->num] < end[num]) {
				end[vn->num] = end[num];
			}
			if ((--priority[vn->num]) == 0) {
				addQ(vn->num, &q);
			}
			vn = vn->front;
		}

	}
	printf("%d", ans);
	return 0;
}

#endif
