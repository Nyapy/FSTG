#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct path {
	int dist;;
	path* next;
}path;

typedef struct vector {
	int size = 0;
	path* head, * tail;

	void push(path* tem) {
		if (size) {
			tail->next = tem;
		}
		else {
			head = tem;
		}
		tail = tem;
		size++;
	}

	void clear() {
		if (!size) return;
		path tem = *head;
		path* z = head;
		for (int i = 0; i < size - 1; i++) {
			free(z);
			z = tem.next;
			tem = *tem.next;
		}
		free(z);
		size = 0;
	}
};


typedef struct test {
	vector t;
	int a;
};

test a, b;


int main() {


	for (int i = 0; i < 5; i++) {
		path* tem = (path*)malloc(sizeof(path));
		tem->dist = i + 1;
		a.t.push(tem);
	}

	b.t = a.t;
	for (int i = 6; i < 10; i++) {
		path* tem = (path*)malloc(sizeof(path));
		tem->dist = i + 1;
		a.t.push(tem);
	}


	path *tm = a.t.head;
	for (int i = 0; i < a.t.size; i++) {
		printf("%d ", tm->dist);
		tm = tm->next;
	}
	printf("\n ");
	tm = b.t.head;
	for (int i = 0; i < a.t.size; i++) {
		printf("%d ", tm->dist);
		tm = tm->next;
	}
	return 0;
}

#endif
