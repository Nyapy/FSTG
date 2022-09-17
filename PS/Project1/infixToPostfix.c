#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


char sic;

char OP[100], ABC[100];
int op=0, abc=0;

int main() {
	scanf("%s", ABC);
	while (1) {
		sic = ABC[abc];

		if (sic == '\0' || sic == '\n') {
			while (op) {
				op--;
				if (OP[op] != '('){
					printf("%c", OP[op]);
				}
			}
			break;
		}

		abc++;

		if ('A' <= sic && sic <= 'Z') {
			printf("%c", sic);
		}
		else if (sic == '(') { 
			OP[op++] = '(';
 		}
		else if (sic == ')') {
			while (op) {
				op--;
				if (OP[op] != '(') {
					printf("%c", OP[op]);
				}
				else {
					break;
				}
			}
		}
		else {
			if (sic == '+' || sic == '-') {
				while (op) {
					if (OP[op - 1] != '(') {
						printf("%c", OP[--op]);
					}
					else {
						break;
					}
				}
				OP[op++] = sic;

			}
			else {
				while (op) {
					if (OP[op - 1] == '*' || OP[op - 1] == '/') {
						printf("%c", OP[--op]);
					}
					else {
						break;
					}
				}

				OP[op++] = sic;
			}
		}




		//printf("%d", sic);

	}
	return 0;
}
#endif