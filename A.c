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
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        ll first = -1, second = -1;
        for (int i = 0; i < n; i++) {
            ll x;
            scanf("%lld", &x);
            if (x >= first) {
                second = first;
                first = x;
            } else if (x > second) {
                second = x;
            }
        }
        printf("%lld\n", first + second);
    }
}

int main(void) {
    solve();
    return 0;
}
