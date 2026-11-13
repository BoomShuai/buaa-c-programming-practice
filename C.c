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

void solve(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        ll x0, y0, px, py, fx, fy;
        ll sum = 0;
        scanf("%lld%lld", &x0, &y0);
        px = x0;
        py = y0;
        for (int i = 1; i < n; i++) {
            scanf("%lld%lld", &fx, &fy);
            sum += px * fy - fx * py;
            px = fx;
            py = fy;
        }
        sum += px * y0 - x0 * py;
        if (sum < 0) sum = -sum;
        printf("%lld\n", sum / 2);
    }
}

int main(void) {
    solve();
    return 0;
}
