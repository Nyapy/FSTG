#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N, M;
int miro[2000][2000];
typedef struct node {
	int x, y;
	node *back;
};

typedef struct queue {
	int size;
	node* head, * tail;

	void add(int x, int y) {
		node* tem = (node*)malloc(sizeof(node));
		tem->x = x;
		tem->y = y;

		if (size++) {
			tail->back = tem;
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
		head = head->back;
		free(tem);
		return ret;
	}

};

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };


int dx8[8] = { 0,1,0,-1,-1,1,1,-1 };
int dy8[8] = { -1,0,1,0, -1,-1,1,1 };


int visited[2000][2000];
queue q, wall;

void bfs(int x, int y) {
	visited[y][x] = 1;
	q.add(x, y);
	if (x || y) wall.add(x, y);

	while (q.size) {
		node tn = q.pop();
		if (x || y) {
			for (int k = 0; k < 8; k++) {
				int nx = tn.x + dx8[k];
				int ny = tn.y + dy8[k];

				if (0 <= nx && nx < M && 0 <= ny && ny < N) {
					if (!visited[ny][nx] && miro[ny][nx] == miro[y][x]) {
						visited[ny][nx] = visited[tn.y][tn.x] + 1;
						q.add(nx, ny);
						wall.add(nx, ny);
					}
				}
			}
		}
		else {
			for (int k = 0; k < 4; k++) {
				int nx = tn.x + dx[k];
				int ny = tn.y + dy[k];

				if (0 <= nx && nx < M && 0 <= ny && ny < N) {
					if (!visited[ny][nx] && miro[ny][nx] == miro[y][x]) {
						visited[ny][nx] = visited[tn.y][tn.x] + 1;
						q.add(nx, ny);
					}
				}
			}
		}

	}

}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &miro[i][j]);
		}
	}

	bfs(0, 0);

	if (!visited[N - 1][M - 1]) {
		printf("0");
		return 0;
	}

	for (int i = 1; i < M; i++) {
		if (miro[0][i]) bfs(i, 0);
	}
	for (int i = 1; i < N; i++) {
		if (miro[i][M-1]) bfs(M-1, i);
	}

	while (wall.size) {
		node tn = wall.pop();
		for (int k = 0; k < 8; k++) {
			int nx = tn.x + dx8[k];
			int ny = tn.y + dy8[k];
			if ((nx == 0 && ny == 0) || (nx == M - 1 && ny == N - 1)) continue;

			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				miro[ny][nx] = 1;
			}
		}
	}
	for (int i = 1; i < M; i++) {
		miro[0][i] = 1;
	}
	for (int i = 1; i < N-1; i++) {
		miro[i][M - 1] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
	bfs(0, 0);

	if (!visited[N - 1][M - 1]) {
		printf("1");
		return 0;
	}
	else {
		printf("2");
	}




	return 0;
}

#endif
