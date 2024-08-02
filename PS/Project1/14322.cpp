#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int T, N;
char name[25], leader[25];

bool alpha[26];
int main() {
	scanf("%d ", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d ", &N);
		int leaders = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 26; j++) {
				alpha[j] = false;
			}



			fgets(name, sizeof(name),stdin);
			int j = 0;
			int cnt = 0;
			while (name[j] != '\n') {
				if (name[j] == ' ') { j++; continue; }
				if (!alpha[name[j] - 'A']) {
					alpha[name[j] - 'A'] = true;
					cnt++;
				}
				j++;
			}
			name[j] = '\0';
			j = 0;
			if (leaders < cnt) {
				leaders = cnt;
				while (name[j]) {
					leader[j] = name[j];
					j++;
				}
				leader[j] = '\0';

			}
			else if(leaders == cnt) {
				while (name[j] || leader[j] ) {
					if (name[j] == leader[j]) { j++; continue; }
					else if (name[j] < leader[j]) {
						int k = 0;
						while (name[k]) {
							leader[k] = name[k];
							k++;
						}
						leader[k] = '\0';
						break;
					}
					else {
						break;
					}
				}
			}
		}

		printf("Case #%d: %s\n", tc, leader);
	}

	return 0;
}

#endif