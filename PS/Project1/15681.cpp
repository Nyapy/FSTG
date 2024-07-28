#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Vnode {
	int num;
	Vnode* next;
}vn;

typedef struct Vector {
	int size;
	vn* head, * tail;

	void push(int n) {
		vn* tem = (vn*)malloc(sizeof(vn));
		tem->num = n;
		if (size) {
			tail->next = tem;
		}
		else {
			head = tem;
		}
		tail = tem;
		size++;
	};

}vector;

vector path[100001];

int N, R, Q;
int V, U;

typedef struct Tree {
	int size; 
	int par;
	vector ch;
}Tree;

Tree tree[100001];


int makeTree(int n, int p) {
	tree[n].par = p;
	tree[n].size = 1;
	vn *tem = path[n].head;
	for (int i = 0; i < path[n].size; i++){
		if (tem->num == p) {
			tem = tem->next;
			continue;
		};
		tree[n].ch.push(tem->num);
		tree[n].size += makeTree(tem->num, n);
		tem = tem->next;
	}
	return tree[n].size;
}


int main() {
	scanf("%d %d %d", &N, &R, &Q);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &U, &V);
		path[U].push(V);
		path[V].push(U);
	}
	makeTree(R,-1);
	for (int i = 0; i < Q; i++) {
		scanf("%d", &U);
		printf("%d\n", tree[U].size);
	}

}

#endif