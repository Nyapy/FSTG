#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int R, C;
char field[255][255];
int visited[250][250];

int sheep, wolves;

typedef struct node {
	int x, y;
	node* next;
};

typedef struct queue {
	int size;
	node* head, * tail;

	void push(int x, int y) {
		node* tem = (node*)malloc(sizeof(node));
		tem->x = x;
		tem->y = y;
		if (size++) {
			tail->next = tem;
		}
		else {
			head = tem;
		}
		tail = tem;
	}

	node pop() {
		node ret = *head;
		node* tem = head;
		head = head->next;
		free(tem);
		size--;
		return ret;
	}

};

queue q;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int area;

void bfs(int x, int y) {
	area++;
	visited[y][x] = area;
	q.push(x, y);
	int notal = 1;
	int ts = 0;
	int tw = 0;
	if (field[y][x] == 'o') ts++;
	else if (field[y][x] == 'v') tw++;

	while (q.size) {
		node tn = q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = tn.x + dx[k];
			int ny = tn.y + dy[k];
			
			if (0 <= nx && nx < C && 0 <= ny && ny < R) {
				if (visited[ny][nx] || field[ny][nx] == '#') continue;
				visited[ny][nx] = area;
				q.push(nx, ny);
				if (field[ny][nx] == 'o') ts++;
				else if (field[ny][nx] == 'v') tw++;
			}
			else {
				notal = 0;
			}
		}
	}
	if (notal) {
		if (ts > tw) sheep += ts;
		else wolves += tw;
	}
}

int main() {

	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		scanf("%s", field[i]);
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j]|| field[i][j] == '#') continue;
			bfs(j, i);
		}
	}
	printf("%d %d", sheep, wolves);

	return 0;
}

#endif