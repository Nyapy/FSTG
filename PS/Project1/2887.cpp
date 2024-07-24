#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct star {
	int num;
	int xyz[3];
}star;

star stars[100000];
star* sorted[3][100000];
star* copy[100000];
void merge(int left, int right, int xyz) {
	int mid = (left + right) / 2;
	int i = left, j = mid + 1, k = left;
	
	while (i <= mid && j <= right) {
		if (sorted[xyz][i]->xyz[xyz] < sorted[xyz][j]->xyz[xyz]) copy[k++] = sorted[xyz][i++];
		else copy[k++] = sorted[xyz][j++];
	}

	while (i <= mid) copy[k++] = sorted[xyz][i++];
	while( j <=right) copy[k++] = sorted[xyz][j++];

	for (k = left; k <= right; k++) {
		sorted[xyz][k] = copy[k];
	}
}

void mergeSort(int left, int right, int xyz) {
	if (left == right) return;
	int mid = (left + right) / 2;
	mergeSort(left, mid, xyz); 
	mergeSort(mid+1, right, xyz);
	merge(left, right, xyz);
}


typedef struct path {
	int from, to, dist;
}path;

typedef struct pq {
	int size;
	path* data[300001];

	void push(int f, int t, int d) {
		path* tem = (path*)malloc(sizeof(path));
		tem->from = f, tem->to = t, tem->dist = d;
		int ch = ++size;
		while (ch > 1 && data[ch / 2]->dist > tem->dist) {
			data[ch] = data[ch / 2];
			ch /= 2;
		}
		data[ch] = tem;
	}

	path* pop() {
		path* ret = data[1];
		path* tem = data[size--];
		int par = 1, ch = 2;
		while (ch <= size) {
			if (ch < size && data[ch]->dist > data[ch + 1]->dist) ch++;
			if (data[ch]->dist > tem->dist) break;
			data[par] = data[ch];
			par = ch;
			ch *= 2;
		}
		data[par] = tem;
		return ret;
	}

};

int N, x, y, z;
int ans=0;
pq q;

int absd(int a, int b) {
	if (a > b) return a - b;
	return b - a;

}

int par[100000];

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void unionFind(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) par[b] = a;
	else par[a] = b;
}
int linked(int a, int b) {
	a = find(a);
	b = find(b);
	return a == b ? 1 : 0;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &x, &y, &z);
		stars[i].xyz[0] = x;
		stars[i].xyz[1] = y;
		stars[i].xyz[2] = z;
		stars[i].num = i;
		for (int j = 0; j < 3; j++) sorted[j][i] = &stars[i];
		par[i] = i;

	}
	for (int j = 0; j < 3; j++) mergeSort(0, N-1, j);

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < N - 1; i++) {
			q.push(sorted[j][i]->num, sorted[j][i + 1]->num, absd(sorted[j][i]->xyz[j], sorted[j][i+1]->xyz[j]));
		}
	}
	int cnt = 0;
	while (cnt < N - 1) {
		path* tem = q.pop();
		if (linked(tem->from, tem->to)) continue;
		unionFind(tem->from, tem->to);
		ans += tem->dist;
		cnt++;
	}


	printf("%d", ans);

}

#endif