#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


typedef struct Vnode {
	int val;
	int seq;
}vn;


typedef struct Node {
	long long dist;
	int x, y, xy;

}node;

struct cmp {
	bool operator()(node t, node u) {
		return t.dist > u.dist;
	}
};

priority_queue<node, vector<node>, cmp> pq;

int M, N, K;
vector<vn> xsw[100005], ysw[100005];
vn* temv;
long long visited[200001][2];

int x, y, xy;
long long dist, di;

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

vn vtem;

int main() {
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i <= K; i++) {
		visited[i][0] = 99999999999;
		visited[i][1] = 99999999999;
	}
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &x, &y);
		vtem.val = y;
		vtem.seq = i;
		xsw[x].push_back(vtem);
		vtem.val = x;
		ysw[y].push_back(vtem);
	}

	node tem;
	tem.dist = 0;
	tem.x = 1, tem.y = 1, tem.xy = 1;

	pq.push(tem);

	long long ans = 0;

	if (!xsw[M].size() && !ysw[N].size()) {
		pq.pop();
	}

	vtem.val = N;
	vtem.seq = K;
	xsw[M].push_back(vtem);
	vtem.val = M;
	ysw[N].push_back(vtem);
	node t;
	while (!pq.empty()) {
		tem = pq.top();
		di = tem.dist, x = tem.x, y = tem.y, xy = tem.xy;
		pq.pop();
		if ((x == M) && (y == N)) {
			ans = di;
			break;
		}

		if (xy) {
			for (int i = 0; i < xsw[x].size(); i++) {
				dist = di + abs(y - (xsw[x][i].val)) + 1;
				if (visited[xsw[x][i].seq][0] > dist) {
					visited[xsw[x][i].seq][0] = dist;
					t.dist = dist, t.x = x, t.y = xsw[x][i].val, t.xy = 0;
					pq.push(t);
				}
			}
		}
		else {
			for (int i = 0; i < ysw[y].size(); i++) {
				dist = di + abs(x - (ysw[y][i].val)) + 1;
				if (visited[ysw[y][i].seq][1] > dist) {
					visited[ysw[y][i].seq][1] = dist;
					t.dist = dist, t.x = ysw[y][i].val, t.y = y, t.xy = 1;
					pq.push(t);
				}

			}
		}

	}

	printf("%lld", ans - 1);

	return 0;
}

#endif
