#if 0
#include <stdio.h>
#include <stdlib.h>
int N, M;
int pop[50];
int ans=0;
typedef struct qnode {
	int num;
	qnode* front, * back;
}qn;

typedef struct circular {
	qnode* head, * tail;
	qnode* now;

	void push(int a) {
		qn* tem = (qn*)malloc(sizeof(qn));

	}

	void pop() {
		qn* tem= now;
		head = now->back;
		head->front = tail;
		tail->back = head;
		free(tem);
	}

	void find(int a) {
		if (head->num == a) {
			pop();
			return;
		}
		qn* left = head, * right = head;
		int cnt = 0;
		while (++cnt) {
			left = left->front;
			right = right->back;
			if (left->num == a) {
				head = left;
				pop();
				ans += cnt;
				break;
			}
			if (right->num == a) {
				head = right;
				pop();
				ans += cnt;
				break;
			}

		}

	}

}cq;


cq q;
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		
	}
	int tem;
	for (int i = 0; i < M; i++) {
		scanf("%d", &tem);
		q.find(tem);
	}


	return 0;
}
#endif