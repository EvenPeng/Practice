#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int  T, n, b, e, m, p, tm, s;
    int  len, nice[20000], oidx[20000], ss[20000];
    int *idx = oidx + 1;
    oidx[0]  = 0;

    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d", &n);

        len = 1;
        scanf("%d", nice);
        idx[0] = 1;
        for (int i = 2; i < n; ++i) {
            scanf("%d", nice + len);
            if ((nice[len] > 0 && nice[len - 1] > 0) || (nice[len] < 0 && nice[len - 1] < 0)) {
                nice[len - 1] += nice[len];
                idx[len - 1] = i;
            }
            else {
                idx[len] = i;
                len++;
            }
        }
        if (nice[len - 1] < 0) len--;

        for (int i = 2 + nice[0] > 0 ? 0 : 1; i < len; i += 2)
            ss[i] = nice[i] + nice[i - 1];

        m = 0;
        p = -1;
        for (int i = nice[0] > 0 ? 0 : 1; i < len; i += 2) {
            tm = nice[i];
            if (tm > m || (tm == m && p < idx[i] - idx[i - 1])) {
                b = i;
                e = i;
                p = idx[i] - idx[i - 1];
                m = tm;
            }
            for (int j = i + 2; j < len; j += 2) {
                tm += ss[j];
                if (tm > m || (tm == m && p < idx[j] - idx[i - 1])) {
                    b = i;
                    e = j;
                    p = idx[e] - idx[b - 1];
                    m = tm;
                }
            }
        }

        if (m > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", t, idx[b - 1] + 1, idx[e] + 1);
        else
            printf("Route %d has no nice parts\n", t);
    }

    return 0;
}
