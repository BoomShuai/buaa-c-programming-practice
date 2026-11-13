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

char s[100005];

void solve(void) {
    int ans = 0;
    while (fgets(s, sizeof(s), stdin)) {
        int ok = 0;
        char *p = strtok(s, " \n\r");
        while (p) {
            int len = strlen(p);
            for (int i = 0; i < len; i++) {
                if (p[i] >= 'A' && p[i] <= 'Z') p[i] = p[i] - 'A' + 'a';
            }
            if (len >= 3 && p[0] == 'c' && p[1] == 'a' && p[2] == 'c') ok = 1;
            if (len >= 3 && p[len - 3] == 't' && p[len - 2] == 'u' && p[len - 1] == 's') ok = 1;
            if (strstr(p, "cactus") != NULL) ok = 1;
            if (ok) break;
            p = strtok(NULL, " \n\r");
        }
        ans += ok;
    }
    printf("%d\n", ans);
}

int main(void) {
    solve();
    return 0;
}
