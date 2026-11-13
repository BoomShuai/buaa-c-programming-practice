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

ull f[100];
int tot;

int day(ull x) {
    int l = 1, r = tot, ans = tot;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (f[mid] >= x) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}

ull fa(ull x) {
    if (x == 1) return 1;
    int d = day(x);
    return f[d] - x + 1;
}

int dep(ull x) {
    int res = 0;
    while (x != 1) {
        x = fa(x);
        res++;
    }
    return res;
}

void solve(void) {
    f[1] = f[2] = 1;
    tot = 2;
    while (f[tot] <= (1ULL << 61)) {
        tot++;
        f[tot] = f[tot - 1] + f[tot - 2];
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        ull a, b;
        scanf("%llu%llu", &a, &b);
        int da = dep(a), db = dep(b);
        while (da > db) a = fa(a), da--;
        while (db > da) b = fa(b), db--;
        while (a != b) {
            a = fa(a);
            b = fa(b);
        }
        printf("%llu\n", a);
    }
}

int main(void) {
    solve();
    return 0;
}
