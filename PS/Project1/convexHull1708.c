#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
	long long x, y;
}pt;

pt point[100001], temp, stemp[100001];
int N;

long long ccw(pt a, pt b, pt c) {
	long long ret = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
	return ret;
}

typedef struct Snode {
	pt* point;
	struct Snode* front;
}snode;

typedef struct Stack {
	snode* head, *tail;
	int size;
}stack;

void addStack(stack * st, pt* point) {
	snode* ns = (snode*)malloc(sizeof(snode));
	ns->point = point;
	if (st->size == 0) {
		st->head = ns;
	}
	else {
		ns->front = st->tail;
	}
	st->tail = ns;
	st->size++;
}

pt* popStack(stack* st) {
	if (st->size == 0) {
		return NULL;
	}
	snode* ret = (snode*)malloc(sizeof(snode));
	ret = st->tail;
	st->tail = st->tail->front;
	st->size--;
	return ret->point;
}

void Sort(int left, int right) {
	int mid = (left + right) / 2;
	int i=left, j= mid+1, k = left;
	pt tem;
	long long c;
	while (i <= mid && j <= right) {
		c = ccw(point[0], point[i], point[j]);
		if (c > 0) {
			stemp[k++] = point[i++];
		}
		else if (c < 0) {
			stemp[k++] = point[j++];
		}
		else {
			if (point[i].y == point[j].y) {
				if (point[i].x < point[j].x) {
					stemp[k++] = point[i++];
				}
				else {
					stemp[k++] = point[j++];
				}
			}
			else if (point[i].x == point[j].x) {
				if (point[i].y < point[j].y) {
					stemp[k++] = point[i++];
				}
				else {
					stemp[k++] = point[j++];
				}
			}
			else {
				if (point[i].y < point[j].y) {
					stemp[k++] = point[i++];
				}
				else {
					stemp[k++] = point[j++];
				}
			}
		}
	}
	while (i <= mid) {
		stemp[k++] = point[i++];
	}
	while (j <= right) {
		stemp[k++] = point[j++];
	}

	k = left;
	while (k <= right) {
		point[k] = stemp[k];
		k++;
	}
}

void mergeSort(int left, int right) {
	if (left == right) return;
	mergeSort(left, (left + right) / 2);
	mergeSort(((left + right) / 2)+1, right);
	Sort(left, right);
}


int main() {
	scanf("%d", &N);
	point[0].y = 40001;
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld", &point[i].x, &point[i].y);
		if (point[0].y > point[i].y) {
			temp = point[i];
			point[i] = point[0];
			point[0] = temp;
		}
		else if (point[0].y == point[i].y) {
			if (point[0].x > point[i].x) {
				temp = point[i];
				point[i] = point[0];
				point[0] = temp;
			}
		}
	}
	mergeSort(1, N - 1);

	stack st;
	st.size = 0;

	addStack(&st, &point[0]);
	addStack(&st, &point[1]);
	pt *first, *second, *next;

	int i=2;

	while (i < N) {

		while (st.size >= 2) {
			second = popStack(&st);
			first = popStack(&st);
			next = &point[i];

			addStack(&st, first);
			if (ccw(*first, *second, *next) > 0) {
				addStack(&st, second);
				break;
			}
		}
		addStack(&st, &point[i]);
		i++;
	}

	printf("%d", st.size);
	return 0;
}
#endif