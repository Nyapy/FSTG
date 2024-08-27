#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, K;

int visited[500001][2];

typedef struct node {
	int v, subin, turn;
	node* next;
};

typedef struct queue {
	int size;
	node* head, * tail;

	void push(int val, int subin, int turn){
		node* tem = (node*)malloc(sizeof(node));
		tem->v = val;
		tem->subin = subin;
		tem->turn = turn;
		if (size++) {
			tail->next = tem;
		}
		else {
			head = tem;
		}
		tail = tem;
	}

	node pop() {
		size--;
		node ret = *head;
		node* tem = head;
		head = head->next;
		free(tem);
		return ret;
	}
};
queue q;

int bfs() {
	if (N == K) return 0;
	q.push(N, 1, 0);
	q.push(K, 0, 0);
	visited[N][0] = 0;
	int time = 1;
	while (q.size) {
		node tq = q.pop();
		if (tq.subin) {
			if (tq.v - 1 >= 0 && !visited[tq.v - 1][time % 2]) {
				visited[tq.v - 1][time%2] = tq.turn + 1;
				q.push(tq.v - 1, 1, tq.turn + 1);
			}
			if (tq.v + 1 <= 500000 && !visited[tq.v + 1][time % 2]) {
				visited[tq.v + 1][time % 2] = tq.turn + 1;
				q.push(tq.v + 1, 1, tq.turn + 1);
			}
			if (tq.v * 2 <= 500000 && !visited[tq.v * 2][time % 2]) {
				visited[tq.v * 2][time % 2] = tq.turn + 1;
				q.push(tq.v *2, 1, tq.turn + 1);
			}
		}
		else {
			if (tq.v + time <= 500000) {
				if (visited[tq.v + time][time % 2] && visited[tq.v + time][time % 2] <= time) return time;
				q.push(tq.v+ time, 0, 0);
				time++;
			}
			else {
				return -1;
			}
		}
	}
}

int main() {

	scanf("%d %d", &N, &K);
	printf("%d", bfs());
	return 0;
}

#endif
