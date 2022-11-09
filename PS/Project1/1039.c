#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char N[10];
int K, visited[11][1000001];

int cnt;

char* itos(int in, char* temp) {
	int i = 0;
	while (in) {
		temp[i++] = (in % 10)+48;
		in /= 10;
	}
	temp[i] = '\n';
	return temp;
}

int stoi(char* temp) {
	int ret = 0;
	int jari = 1;
	for (int i = cnt - 1; i >= 0; i--) {
		ret += jari * (temp[i] - '0');
		jari *= 10;
	}
	return ret;
}

int ans = -1;

void dfs(char* m, int k) {
	int tem = stoi(m);
	if (k == K) {
		if (ans < tem) {
			ans = tem;
		}
		return;

	}

	char t;
	for (int i = 0; i < cnt; i++) {
		for (int j = i+1; j < cnt; j++) {
			t = m[i];
			m[i] = m[j];
			m[j] = t;
			tem = stoi(m);
			if (!visited[k + 1][tem] && m[0] !='0') {
				visited[k + 1][tem] = 1;
				dfs(m, k + 1);
			}
			m[j] = m[i];
			m[i] = t;
		}
	}
}
int main() {
	//char tem[10];
	//for (int i = 0; i < 10; i++) {
	//	tem[i] = 0;
	//}

	scanf("%s %d", N, &K);
	while (N[cnt]) cnt++;

	visited[0][stoi(N)] = 1;
	dfs(N, 0);
	printf("%d", ans);
	
	return 0;
}

#endif
