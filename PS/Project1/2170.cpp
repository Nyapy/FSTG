#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ans;
int n;
int a, b;

typedef struct node {
	int s, e;
};

node point[1000000];
node toint[1000000];
void merge(int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid+1;
	int k = left;

	while (i <= mid && j <= right) {
		if (point[i].s < point[j].s) toint[k++] = point[i++];
		else toint[k++] = point[j++];
	}

	while(i <= mid) toint[k++] = point[i++];
	while (j <= right) toint[k++] = point[j++];
	for (k = left; k <= right; k++) point[k] = toint[k];
}

void sort(int left, int right) {
	if (left == right) return;
	int mid = (left + right) / 2;

	sort(left, mid);
	sort(mid +1, right);
	merge(left, right);

}

int main() {
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);	
		point[i].s = a;
		point[i].e = b;
	}
	sort(0, n - 1);
	int tems = point[0].s;
	int teme = point[0].e;

	for (int i = 1; i < n; i++) {
		if (teme < point[i].s) {
			ans += teme - tems;
			tems = point[i].s;
			teme = point[i].e;
		}
		else {
			if (teme < point[i].e) teme = point[i].e;
		}
	}

	ans += teme - tems;
	printf("%d", ans);
	return 0;
}

#endif
