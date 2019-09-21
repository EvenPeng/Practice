#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int T, n, b, e, m, p, tm;
    int len, nice[20000], idx[20000];

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

        m = 0;
        p = 0;
        for (int i = 0; i < len; ++i) {
            if (nice[i] > 0) {
                tm = 0;
                for (int j = i; j < len; ++j) {
                    tm += nice[j];
                    if (tm > m || (tm == m && p < (idx[j] - (i == 0 ? 0 : idx[i - 1])) + 1)) {
                        b = i == 0 ? 0 : idx[i - 1];
                        e = idx[j];
                        p = e - b + 1;
                        m = tm;
                    }
                }
            }
        }

        if (m > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", t, b + 1, e + 1);
        else
            printf("Route %d has no nice parts\n", t);
    }

    return 0;
}
