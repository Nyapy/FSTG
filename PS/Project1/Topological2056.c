#if 0
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

		for (int j = 0; j < oper[i].prio; j++) {//해당 작업을 필요로 하는 작업들의 목록을 표시함.
			scanf(" %d", &tem);

			node *a = (node*)malloc(sizeof(node));
			a->op = i;
			a->front = oper[tem].vec.last;
			oper[tem].vec.last = a;
			oper[tem].vec.size ++;
		}

		if (oper[i].prio == 0) { //선작업이 없는 경우를 큐에 넣음
			qnode *qn= (qnode*)malloc(sizeof(qnode));
			qn->oper = &oper[i];
			qn->back = NULL;
			oper[i].end = 0;
			addQ(qn, &q);
		}
	}

	int ans=0;
	while (q.size > 0) {// 큐가 빌 때까지 돌림.
		qnode *qn = popQ(&q);
		
		
		qn->oper->end += qn->oper->time; //작업의 시작시간와 소요 시간을 더해서 끝나는 시간을 표시함.

		if (ans < (qn->oper->end)) {//작업 종료 시간이 정답보다 크다면 update
			ans = qn->oper->end;
		}

		int cy = qn->oper->vec.size; //해당 작업을 선행으로 해야하는 작업들 
		
		node* a = qn->oper->vec.last;
		for (int i = 0; i < cy; i++) {
			 //벡터 뒤에서부터 하나씩 읽음

			(oper[a->op].prio)--;

			if (oper[a->op].end < qn->oper->end) { //해당 작업의 시작시간을 설정해줌.
				oper[a->op].end = qn->oper->end;
			}
			if (oper[a->op].prio == 0) { //선행작업이 없다면 Q에 넣어줌
				qnode* newq = (qnode*)malloc(sizeof(qnode));
				newq->oper = &oper[a->op];
				newq->back = NULL;
				addQ(newq, &q);
			}

			a = qn->oper->vec.last->front;
		}
		free(qn);
	}

	printf("%d", ans);

	return 0;
}

#endif
