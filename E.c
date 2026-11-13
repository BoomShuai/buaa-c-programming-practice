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

#define N 200005

int op[N], cnt;
ll a[N], b[N], v[N], c[N], sum[N];

int cmp(const void *x, const void *y) {
    ll p = *(ll *)x, q = *(ll *)y;
    if (p < q) return -1;
    if (p > q) return 1;
    return 0;
}

int find(ll x, int n) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (v[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

void add(ll tr[], int x, ll y, int n) {
    while (x <= n) {
        tr[x] += y;
        x += x & -x;
    }
}

ll ask(ll tr[], int x) {
    ll res = 0;
    while (x) {
        res += tr[x];
        x -= x & -x;
    }
    return res;
}

int kth(ll k, int n) {
    int x = 0;
    ll now = 0;
    for (int i = 1 << 18; i; i >>= 1) {
        int y = x + i;
        if (y <= n && now + c[y] < k) {
            x = y;
            now += c[y];
        }
    }
    return x + 1;
}

void solve(void) {
    int q, m = 0;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d", &op[i]);
        if (op[i] == 1) {
            scanf("%lld%lld", &a[i], &b[i]);
            v[++m] = a[i];
        }
    }
    qsort(v + 1, m, sizeof(ll), cmp);
    int n = 0;
    for (int i = 1; i <= m; i++) {
        if (i == 1 || v[i] != v[i - 1]) v[++n] = v[i];
    }
    ll num = 0, all = 0, addb = 0;
    for (int i = 1; i <= q; i++) {
        if (op[i] == 1) {
            int p = find(a[i], n);
            add(c, p, 1, n);
            add(sum, p, a[i], n);
            num++;
            all += a[i];
            addb += b[i];
        } else {
            int p = kth((num + 1) / 2, n);
            ll x = v[p];
            ll lc = ask(c, p), ls = ask(sum, p);
            ll rc = num - lc, rs = all - ls;
            printf("%lld %lld\n", x, x * lc - ls + rs - x * rc + addb);
        }
    }
}

int main(void) {
    solve();
    return 0;
}
