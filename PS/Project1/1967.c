#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct vnode {
	int num, dist;
	struct vnode* next;
}vn;

typedef struct vector {
	vn* first, * last;
	int size;
}vec;

void addV(vec *v, int child, int dist) {
	vn* newv = (vn*)malloc(sizeof(vn));
	newv->num = child;
	newv->dist = dist;
	if (v->size == 0) {
		v->first = newv;
	}
	else {
		v->last->next= newv;
	}
	v->last = newv;
	v->size++;

}


typedef struct treenode {
	int dist;
	vec child;
}tn;

tn tree[10001];

int n,p,c,d;
int ans = 0;
int circle(tn* tr, int num) {
	if (tr->child.size == 0) return tr->dist;
	int hap = 0;
	vn *tem;

	int first=0, second=0, a;
	tem = tr->child.first;
	for (int i = 0; i < tr->child.size; i++) {
		a= circle(&tree[tem->num], tem->num);
		if (first < second) {
			if (a > first) {
				first = a;
			}
		}
		else {
			if (a > second) {
				second = a;
			}
		}
		tem = tem->next;
	}

	if (first + second > ans) {
		ans = first + second;
	}	
	if (first > second) return hap = tr->dist+ first;
	else return hap = second+tr->dist;
}


int main() {

	scanf("%d", &n);

	for (int i = 0; i < n-1; i++) {
		scanf("%d %d %d", &p,&c,&d);
		addV(&tree[p].child, c, d);
		tree[c].dist = d;
	}
	circle(&tree[1],1);
	printf("%d", ans);
	return 0;
}

#endif
