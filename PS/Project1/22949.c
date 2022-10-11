#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct Qnode {
	int x, y, di;
	struct Qnode* back;
}qnode;

typedef struct Queue {
	int size;
	qnode* head, * tail;
}queue;

void addq(int x, int y, int di, queue* q) {
	qnode* nq = (qnode*)malloc(sizeof(qnode));
	nq->x = x, nq->y = y, nq->di=di;

	if (q->size == 0) {
		q->head = nq;
	}
	else {
		q->tail->back = nq;
	}
	q->tail = nq;
	q->size++;
}

qnode* popq(queue* q) {
	if (q->size == 0) {
		return NULL;
	}
	qnode* ret = q->head;
	q->head = q->head->back;
	q->size--;

	return ret;
}

char miro[4][505][505];
int visited[4][505][505];
int k;
char temp[4][4];

int sx, sy, ex, ey;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
queue q;

int main() {
	scanf("%d", &k);

	for (int i = 0; i < k*4; i++) {
		scanf("%s", miro[0][i]);
	}



	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (miro[0][i][j] == 'S') {//시작점을 큐에 넣음
				sx = j, sy = i;
				addq(sx, sy, 0, &q);
				visited[0][sy][sx] = 1;
			}
			else if (miro[0][i][j] == 'E') {
				ex = j, ey = i;
			}
		}
	}


	for (int a = 1; a < 4; a++) { //미로의 각 4*4부분을 0,90,180,270도씩 돌린 미로를 저장함.
		for(int b=0; b<k; b++){
			for(int c=0; c<k; c++){
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						miro[a][4*b+i][4*c+j] = miro[a - 1][4*b+3 - j][4*c+i];
					}
				}
			}
		}
	}

	int tx, ty, td;
	int ans = -1;
	while (q.size) {
		qnode* ret = popq(&q);
		tx = ret->x, ty = ret->y, td=ret->di;
		int kx = tx % 4, ky = ty % 4;

		if (!visited[(td + 1) % 4][(ty / 4)*4 + kx][4 * (tx / 4) + 3 - ky]) {
			visited[(td + 1) % 4][(ty / 4) *4+ kx][4 * (tx / 4) + 3 - ky] = visited[td][ty][tx] + 1;
			addq(4 * (tx / 4) + 3 - ky, (ty / 4)*4 + kx, (td + 1) % 4, &q);
		}
		if (miro[td][ty][tx] == 'E') {
			ans = visited[td][ty][tx]-1;
			break;
		};
		for (int a = 0; a < 4; a++) {
			int nx = tx + dx[a], ny = ty + dy[a];

			if (0 <= nx && nx < k * 4 && 0 <= ny && ny < k * 4) {
				if ((nx/4 == tx/4) && (ny/4 == ty/4)) {
					kx = nx %4, ky = ny % 4;
					
					if (miro[((td + 1) % 4)][(ny/4)*4+kx][4 * (nx / 4) + 3 - ky] != '#') {
						if (!visited[(td + 1) % 4][(ny/4)*4+kx][4 * (nx / 4) + 3 - ky]) {
							visited[(td + 1) % 4][(ny /4)*4 + kx][4 * (nx / 4) + 3 - ky] = visited[td][ty][tx] + 1;
							addq(4 * (nx / 4) + 3 - ky, (ny / 4) + kx, (td + 1) % 4, &q);
						}
					}
				}//Same area
				else {
					if (miro[0][ny][nx] != '#') {
						if (!visited[0][ny][nx]) {
							visited[0][ny][nx] = visited[td][ty][tx] + 1;
							addq(nx, ny, 0, &q);
						}
					}
				}//Diff area
			}
		}
	}
	printf("%d", ans);

	return 0;
}

#endif
