#if 0

#include <stdio.h>
#define MAX 1000000
#define gc getchar_unlocked

void scan_int(int* x)
{
    register int c = gc();
    *x = 0;
    int neg = 0;
    for (; ((c < 48 || c>57) && c != '-'); c = gc());
    if (c == '-') {
        neg = 1;
        c = gc();
    }
    for (; c > 47 && c < 58; c = gc()) {
        *x = (*x << 1) + (*x << 3) + c - 48;
    }
    if (neg)
        *x = -*x;
}
int vals[2 * MAX + 1] = { 0 };

int main(void)
{
    int cnt;
    int n;
    int i;
    scan_int(&cnt);


    for (i = 0; i < cnt; i++) {
        scan_int(&n);
        vals[n + MAX] = 1;
    }
    for (i = 0; i < 2 * MAX + 1; i++) {
        if (vals[i])
            printf("%d\n", i - MAX);
    }


    return 0;
}

#endif