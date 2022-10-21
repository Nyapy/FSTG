#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char fi[1005], se[1005];
int dp[1005], f,s,l, cnt;

int main() {

	for (int i = 1; i < 1005; i++) {
		dp[i] = 1010;
	}
	scanf("%s", fi);
	scanf("%s", se);

	f = 0;
	l = 1;
	int uf = 0;
	while (se[s]) {
		f = 0;
		while (fi[f]) {
			if (fi[f] == se[s]) {
				cnt++;
				int tem=-1;
				for (int i = 1; i <= l; i++) {
					if ((f+1 < i) || (l > s+1)) break;
					if ((dp[i] > f) && tem < f) {
						dp[i] = f;
						if (i == l) uf = 1;
					}
					tem = dp[i];
				}
				if (uf) {
					l++;
					uf = 0;
				}
			}
			f++;
		}
		s ++;
	}
	
	printf("%d", l-1);
	return 0;
}

#endif