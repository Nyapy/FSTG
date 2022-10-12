#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
	int x, y;
}pt;

pt point[100001], temp, stemp[100001];
int N;

int ccw(pt a, pt b, pt c) {
	int ret = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
	return ret;
}


void Sort(int left, int right) {
	int mid = (left + right) / 2;
	int i=left, j= mid+1, k = left;
	pt tem;
	int c;
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
		scanf("%d %d", &point[i].x, &point[i].y);
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

	for (int i = 0; i < N; i++) {
		printf("%d, %d\n", point[i].x, point[i].y);
	}

	return 0;
}
#endif