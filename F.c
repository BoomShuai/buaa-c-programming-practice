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

bool f[55][205][2], g[55][205][2];

void solve(void) {
    char s[105];
    int n;
    scanf("%s", s);
    scanf("%d", &n);
    int len = strlen(s), mid = len + 2;
    f[0][mid][1] = true;
    for (int i = 0; i < len; i++) {
        memset(g, 0, sizeof(g));
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= mid * 2; k++) {
                for (int d = 0; d < 2; d++) {
                    if (!f[j][k][d]) continue;
                    int c = s[i] == 'F' ? 0 : 1;
                    if (j + c <= n) g[j + c][k + (d ? 1 : -1)][d] = true;
                    c = s[i] == 'T' ? 0 : 1;
                    if (j + c <= n) g[j + c][k][d ^ 1] = true;
                }
            }
        }
        memcpy(f, g, sizeof(f));
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if ((n - i) % 2) continue;
        for (int j = 0; j <= mid * 2; j++) {
            if (f[i][j][0] || f[i][j][1]) ans = MAX(ans, abs(j - mid));
        }
    }
    printf("%d\n", ans);
}

int main(void) {
    solve();
    return 0;
}
