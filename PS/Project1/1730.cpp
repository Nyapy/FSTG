#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int N;
char cmd[251];
int visited[250][250];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main() {
	int x = 0, y = 0;
	scanf("%d", &N);
	scanf("%s", &cmd);

	int now = 0;
	while (cmd[now]) {
		int k;
		if (cmd[now] == 'U') k= 0;
		else if (cmd[now] == 'D') k = 1;
		else if (cmd[now] == 'L') k = 2;
		else k = 3;
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			if (k == 0 || k == 1) {
				visited[y][x] = 1 | visited[y][x];
				visited[ny][nx] = 1 | visited[ny][nx];
			}
			else {
				visited[y][x] = 2 | visited[y][x];
				visited[ny][nx] = 2 | visited[ny][nx];
			}
		}
		else {

			now++;
			continue;
		}
		x = nx, y = ny;
		now++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (3 == visited[i][j] & 3) printf("+");
			else if(2 == visited[i][j] & 3) printf("-");
			else if (1 == visited[i][j] & 3) printf("|");
			else printf(".");
		}
		printf("\n");
	}


	return 0;
}

#endif
