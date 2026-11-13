#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef long long ll;
typedef unsigned long long ull;

#define INF 0x3f3f3f3f3f3f3f3fLL
#define INF32 0x3f3f3f3f

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

char a[600][600], b[600][600];
int len;

void clean(char x[600][600]) {
    for (int i = 0; i < 600; i++) {
        for (int j = 0; j < 600; j++) x[i][j] = ' ';
    }
}

void cp(int x, int y) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (a[i][j] == 'o') b[x + i][y + j] = 'o';
        }
    }
}

void solve(void) {
    int n;
    if (scanf("%d", &n) != 1) return;
    clean(a);
    a[0][1] = a[1][0] = a[1][2] = a[2][1] = 'o';
    len = 3;
    for (int i = 1; i <= n; i++) {
        clean(b);
        int t = len;
        if (i % 2) {
            cp(0, 0);
            cp(0, t);
            cp(t, 0);
            cp(t, t);
            len = t * 2;
        } else {
            cp(0, t - 1);
            cp(t - 1, 0);
            cp(t - 1, 2 * t - 2);
            cp(2 * t - 2, t - 1);
            len = 3 * t - 2;
        }
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < len; k++) a[j][k] = b[j][k];
        }
    }
    for (int i = 0; i < len; i++) {
        int r = len - 1;
        while (r >= 0 && a[i][r] == ' ') r--;
        for (int j = 0; j <= r; j++) putchar(a[i][j]);
        putchar('\n');
    }
}

int main(void) {
    solve();
    return 0;
}
