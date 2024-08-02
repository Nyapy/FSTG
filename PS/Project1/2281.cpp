#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int rest[1001];
int hap[1002][1002] ;
int n, m, name;

int small(int a, int b) {
	if (a < b) return a;
	return b;
}

int main() {
	scanf("%d %d", &n, &m);
	int ans = 1000000001;

	for (int i = 1; i <= n; i++) {
		rest[i] = m;
		hap[i][0] = 1000000001;
	}
	rest[0] = m;
	hap[1][0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &name);
		for (int j = 1; j <= i; j++) {
			rest[j] = rest[j] - name;
			if (i > j) rest[j] -= 1;
			if (rest[j] < 0) {
				continue;
			}

			hap[j][i] = hap[j][0] + rest[j] * rest[j];
			hap[i + 1][0] = small(hap[j][i], hap[i + 1][0]);
			if (i == n ) {
				if (ans > hap[j][0]) ans = hap[j][0];
			}
		}
	}

	printf("%d", ans);

}

#endif