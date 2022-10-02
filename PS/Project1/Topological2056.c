#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int op;
	struct Node *front;
}node;

typedef struct V {
	int size;
	node* last;
}vector;


typedef struct Oper {
	int time, end, prio;
	vector vec;
}op;

int N, tem;


typedef struct Qnode {
	op* oper;

	struct Qnode* front, *back;

}qnode;

typedef struct Queue {
	qnode* head, *tail;
	int size;
}queue;

void addQ(qnode* o, queue* q) {

	if (q->size == 0) {
		q->head = o;
	}
	else {
		q->tail->back = o;
	}
	q->tail = o;
	(q->size)++;

}


int main() {

	scanf("%d", & N);

	op oper[10001];

	for (int i = 1; i <= N; i++) {
		scanf(" %d %d", &oper[i].time, &oper[i].prio);
		oper[i].vec.size = 0;
		oper[i].vec.last = NULL;

		for (int j = 0; j < oper[i].prio; j++) {
			scanf(" %d", &tem);

			node *a = (node*)malloc(sizeof(node));
			a->op = i;
			a->front = oper[tem].vec.last;
			oper[tem].vec.last = a;
			oper[tem].vec.size ++;
		}
	}




	return 0;
}

#endif
