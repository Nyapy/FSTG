#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int arr[10000], N, M, tem[10000];
int pr[10000];
void merge(int left, int right) {
	int i = left, mid = (left + right) / 2, j = mid+1;
	int k = left;
	while ((i <= mid) && (j <= right)) {
		if (arr[i] < arr[j]) {
			tem[k++] = arr[i++];
		}
		else {
			tem[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		tem[k++] = arr[i++];
	}
	while (j <= right) {
		tem[k++] = arr[j++];
	}
	k = left;
	while (k <= right) {
		arr[k] = tem[k];
		k++;
	}
}

void sort(int left, int right) {
	if (left == right) return;
	sort(left, (left + right) / 2);
	sort((left + right) / 2 + 1, right);
	merge(left, right);
}

void dfs(int now, int k, int cnt) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[pr[i]]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < cnt; i++) {
		pr[k] = i;
		dfs(i, k + 1, cnt);
	}

}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	sort(0, N - 1);
	int cnt = 1;
	int tem = arr[0];
	for (int i = 1; i < N; i++) {
		if (arr[i] != tem) {
			tem = arr[i];
			arr[cnt++] = arr[i];
		}
	}

	dfs(0, 0, cnt);

	return 0;
}

#endif
