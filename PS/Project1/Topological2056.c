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

qnode *popQ(queue* q) {
	if (q->size == 0) {
		printf("Queue is empty");
		return NULL;
	}
	qnode* ret;

	ret = q->head;

	q->head = q->head->back;
	q->size--;
	return ret;
}

int main() {

	scanf("%d", & N);

	op oper[10001];
	queue q;
	q.size = 0;

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

		if (oper[i].prio == 0) {
			qnode *qn= (qnode*)malloc(sizeof(qnode));
			qn->oper = &oper[i];
			qn->back = NULL;
			oper[i].end = 0;
			addQ(qn, &q);
		}
	}

	int ans=0;
	while (q.size > 0) {
		qnode *qn = popQ(&q);
		
		int cy = qn->oper->vec.size;
		qn->oper->end += qn->oper->time;

		if (ans < (qn->oper->end)) {
			ans = qn->oper->end;
		}

		for (int i = 0; i < cy; i++) {
			node* a = qn->oper->vec.last;

			(oper[a->op].prio)--;
			if (oper[a->op].end < qn->oper->end) {
				oper[a->op].end = qn->oper->end;
			}
			if (oper[a->op].prio == 0) {
				qnode* newq = (qnode*)malloc(sizeof(qnode));
				newq->oper = &oper[a->op];
				newq->back = NULL;
				addQ(newq, &q);
			}

			qn->oper->vec.last = qn->oper->vec.last->front;
			free(a);
		}
		free(qn);
	}

	printf("%d", ans);

	return 0;
}

#endif
