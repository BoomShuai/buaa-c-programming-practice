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

#define N 100005
#define M 1000005

int head[N], ver[M], ne[M], edge[M], tot;
int qv[M], siz;
ll qd[M], d1[N], d2[N];
int s[N];

void add(int x, int y, int z) {
    ver[++tot] = y;
    edge[tot] = z;
    ne[tot] = head[x];
    head[x] = tot;
}

void swap_heap(int x, int y) {
    int tv = qv[x];
    ll td = qd[x];
    qv[x] = qv[y];
    qd[x] = qd[y];
    qv[y] = tv;
    qd[y] = td;
}

void push(int x, ll d) {
    int p = ++siz;
    qv[p] = x;
    qd[p] = d;
    while (p > 1 && qd[p] < qd[p >> 1]) {
        swap_heap(p, p >> 1);
        p >>= 1;
    }
}

void pop(int *x, ll *d) {
    *x = qv[1];
    *d = qd[1];
    qv[1] = qv[siz];
    qd[1] = qd[siz--];
    int p = 1;
    while (1) {
        int t = p, l = p << 1, r = l | 1;
        if (l <= siz && qd[l] < qd[t]) t = l;
        if (r <= siz && qd[r] < qd[t]) t = r;
        if (t == p) break;
        swap_heap(t, p);
        p = t;
    }
}

void dij(int st, ll d[], int n) {
    for (int i = 1; i <= n; i++) d[i] = INF;
    siz = 0;
    d[st] = 0;
    push(st, 0);
    while (siz) {
        int x;
        ll dis;
        pop(&x, &dis);
        if (dis != d[x]) continue;
        for (int i = head[x]; i; i = ne[i]) {
            int y = ver[i];
            if (d[y] > dis + edge[i]) {
                d[y] = dis + edge[i];
                push(y, d[y]);
            }
        }
    }
}

void solve(void) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    for (int i = 1; i <= k; i++) scanf("%d", &s[i]);
    dij(1, d1, n);
    dij(n, d2, n);
    ll ans = INF;
    for (int i = 1; i <= k; i++) ans = MIN(ans, d1[s[i]] + d2[s[i]]);
    printf("%lld\n", ans);
}

int main(void) {
    solve();
    return 0;
}
