#if 0
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* front;
	struct Node* back;
	int value;
}node;

typedef struct Que {
	node* head, *tail;
	int len;
}queue;

void addQue(queue *q, int value) {
	
	node* newNode = (node*)malloc(sizeof(node));
	newNode->value = value;
	newNode->back = NULL;

	if (q->len == 0) {
		q->head = newNode;
	}
	else {
		q->tail->back = newNode;
	}
	//newNode->front = q->tail;
	q->tail = newNode;
	q->len++;
};

node* popQue(queue* q) {
	if (q->len == 0) {
		printf("Queue is empty");
		return NULL;
	}
	node* ret;

	ret = q->head;

	q->head = q->head->back;
	q->len--;
	return ret;
}

int main() {
	queue q;
	q.len = 0;

	node ret;
	node* addr;
	for (int i = 0; i < 9; i++) {
		addQue(&q, i);
	}
	for (int i = 0; i < 10; i++) {
		addr = popQue(&q);
		ret = *addr;
		free(addr);
		printf("ret = %d, addr = %x, addret = %x\n", ret.value, addr, &ret);
	}
	return 0;
}
#endif