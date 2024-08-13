#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 100000000001
int N, M, K, u, v, p;
typedef struct node {
	int dest, k;
	long long dist;
	node* next;
}node;
typedef struct Pvector {
	int size;
	node* head, * tail;
	void add(node* tem) {
		if (size++) {
			tail->next = tem;
		}
		else {
			head = tem;
		}
		tail = tem;
	}
}PV;
PV path[10001];
node doro[100001];

long long visited[21][10001];
typedef struct priority {
	int size=0;
	node* data[2000001];
	void push(int d, long long dist, int k) {
		node* tem = (node*)malloc(sizeof(node));
		tem->dest = d;
		tem->dist = dist;
		tem->k = k;
		int ch = ++size;
		while (ch > 1 && data[ch / 2]->dist > tem->dist) {
			data[ch] = data[ch / 2];
			ch /= 2;
		}
		data[ch] = tem;
	}
	node pop() {
		node ret = *data[1];
		node* tem = data[size--];
		int par = 1;
		int ch = 2;
		while (ch <= size) {
			if (ch <size && data[ch]->dist > data[ch + 1]->dist) ch++;
			if (data[ch]->dist > tem->dist) break;
			data[par] = data[ch];
			par = ch;
			ch *= 2;
		}
		data[par] = tem;
		return ret;
	}
}pq;
pq q;

long long dijk() {
	q.push(1, 0, 0);
	visited[0][1] = 0;

	while (q.size) {
		node tn = q.pop();
		if (visited[tn.k][tn.dest] < tn.dist) continue;

		if (tn.dest == N) return tn.dist ;
		node* now = path[tn.dest].head;
		for (int i = 0; i < path[tn.dest].size; i++) {
			if (visited[tn.k][now->dest] > now->dist + tn.dist) {
				visited[tn.k][now->dest] = now->dist + tn.dist;
				q.push(now->dest, now->dist + tn.dist, tn.k);
			}
			if (tn.k < K && visited[tn.k + 1][now->dest] > tn.dist) {
				visited[tn.k + 1][now->dest] = tn.dist;
				q.push(now->dest, tn.dist, tn.k + 1);
			}
			now = now->next;
		}
	}
	return 0;
}
long long dp[21][10001];

int main() {

	//freopen("revamp.11.in", "r", stdin);

	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {

		for (int j = 0; j <= K; j++) {
			visited[j][i] = INF;
		}
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &u, &v, &p);
		doro[i].dest = v;
		doro[i].dist = p;
		doro[i + M].dest = u;
		doro[i + M].dist = p;
		path[u].add(&doro[i]);
		path[v].add(&doro[i + M]);
	}

	

	printf("%lld", dijk());
	return 0;
}
#endif