#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int T, w, h;
char miro[105][105];

typedef struct node {
	int x, y;
	int prison;
	node* front, * back;
};

typedef struct deque {
	int size;
	node* head, * tail;

	void pushL(int x, int y, int first) {
		node* tem = (node*)malloc(sizeof(node));
		tem->x = x;
		tem->y = y;
		tem->prison = first;
		if (size++) {
			head->front = tem;
			tem->back = head;
		}
		else {
			tail = tem;
		}
		head = tem;
	}
	void pushR(int x, int y, int first) {
		node* tem = (node*)malloc(sizeof(node));
		tem->x = x;
		tem->y = y;
		tem->prison = first;
		if (size++) {
			tail->back = tem;
			tem->front = tail;
		}
		else {
			head = tem;
		}
		tail = tem;
	}

	node pop() {
		node ret = *head;
		node* tem = head;
		head = head->back;
		free(tem);
		size--;
		return ret;
	}
};

deque q;

int visited[3][105][105];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int escape() {
	int ans = 100000;

	bool left = true;
	while (q.size) {
		node tn = q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = tn.x + dx[k];
			int ny = tn.y + dy[k];

			if (0 <= nx && nx <= w+1 && 0 <= ny && ny <= h+1) {
				if (visited[tn.prison][ny][nx]==10001) {

					if (miro[ny][nx] == '.') {
						visited[tn.prison][ny][nx] = visited[tn.prison][tn.y][tn.x];
						q.pushL(nx, ny, tn.prison);
					}
					else if (miro[ny][nx] == '#') {
						visited[tn.prison][ny][nx] = visited[tn.prison][tn.y][tn.x] + 1;
						q.pushR(nx, ny, tn.prison);
					}
					
				}

			}
		}

	}

	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {
			for (int k = 0; k < 2; k++) {
				visited[2][i][j] += visited[k][i][j];
			}

			if (miro[i][j] == '#') {
				visited[2][i][j] -= 2;
			}

			if (visited[2][i][j] < ans) ans = visited[2][i][j];

		}
	}

	return ans;
}


int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		scanf("%d %d", &h, &w);
		int t = 0;
		for (int i =1; i <= h; i++) {
			scanf("%s", &miro[i][0] + 1);

			for (int j = 0; j <= w+1; j++) {
				visited[0][i][j] = 10001;
				visited[1][i][j] = 10001;
				visited[2][i][j] = 10001;
				if (miro[i][j] == '$') {
					miro[i][j] = '.';
					visited[t][i][j] = 0;
					q.pushL(j, i, t++);
				}
			}
		}
		for (int j = 0; j <= w + 1; j++) {
			for (int k = 0; k < 3; k++) {
				visited[k][0][j] = 10001;
				visited[k][h + 1][j] = 10001;
			}
			miro[0][j] = '.';
			miro[h + 1][j] = '.';
		}
		for (int i = 0; i <= h + 1; i++) {
			miro[i][0] = '.';
			miro[i][w + 1] = '.';
			for (int k = 0; k < 3; k++) {
				visited[k][i][0] = 10001;
				visited[k][i][w + 1] = 10001;
			}
		}

		q.pushL(0, 0, t);
		visited[t][0][0] = 0;

		printf("%d\n", escape());


	}


	return 0;
}

#endif
