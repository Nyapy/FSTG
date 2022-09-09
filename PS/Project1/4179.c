#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

typedef struct Node {
	struct Node* front, * back;
	int x, y,t;
	char JF;
}node;

typedef struct Que {
	node* head, * tail;
	int len;
}que;

void addQ(que *q, char jf, int x, int y, int t){
	node* newNode =(node*)malloc(sizeof(node));

	newNode->JF = jf;
	newNode->x = x;
	newNode->y = y;
	newNode->t = t;
	if (q->len == 0) {
		q->head = newNode;
		newNode->front = NULL;
	}
	else {
		q->tail->back = newNode;
		newNode->front = q->tail;
	}
	q->len++;
	q->tail = newNode;
}

node* popQ(que *q) {
	
	if (q->len == 0) {
		printf("que is empty");
		return NULL;
	}
	node* ret;
	ret = q->head;

	q->head = q->head->back;
	q->len--;
	return ret;
}


int main() {
	int R, C, jx,jy,x,y,jf,t;
	char miro[1001][1001];

	scanf("%d %d ", &R, &C);

	que q;
	q.len = 0;
	q.head = NULL;
	q.tail = NULL;	

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf(" %c", &miro[i][j]);
			if (miro[i][j] == 'J') {
				jx = j, jy = i;
			}
			else if (miro[i][j] == 'F') {
				addQ(&q, 'F', j, i,0);
			}
		}
	}
	addQ(&q, 'J', jx, jy,0);

	node* ret;
	while (q.len > 0) {
		ret = popQ(&q);
		x = ret->x;
		y = ret->y;
		t = ret->t;
		jf = ret->JF;
		free(ret);
		for (int k = 0; k < 4; k++) {
			jx = x + dx[k], jy = y + dy[k];
			if (1 <= jx && jx <= C && 1 <= jy && jy <= R) {
				if (miro[jy][jx] != '#') {
					if (jf == 'J') {
						if (miro[jy][jx] == '.') {
							addQ(&q, 'J', jx, jy, t+1);
							miro[jy][jx] = 'J';
						}
					}
					else if (jf == 'F') {
						if (miro[jy][jx] != 'F') {
							addQ(&q, 'F', jx, jy, t+1);
							miro[jy][jx] = 'F';
						}
					}
				}
			}
			else {
				if (jf == 'J') {
					printf("%d", t + 1);
					return 0;
				}
			}
		}
	}

	printf("IMPOSSIBLE");
	return 0;
}


#endif