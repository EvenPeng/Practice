#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    bool flag, time[1000001];
    int  n, m, s, f, p, i, j;

    while (true) {
        scanf("%d %d", &n, &m);
        if (!n && !m) break;

        memset(time, true, sizeof(time));

        flag = true;
        for (i = 0; i < n; ++i) {
            scanf("%d %d", &s, &f);
            for (j = s; j < f && flag; ++j) {
                flag    = time[j];
                time[j] = false;
            }
        }

        for (i = 0; i < m; ++i) {
            scanf("%d %d %d", &s, &f, &p);
            while (flag && s < 1000000) {
                for (j = s; j < f && flag; ++j) {
                    flag    = time[j];
                    time[j] = false;
                }
                s += p;
                f += p;
                if (f > 1000000) f = 1000000;
            }
        }

        if (flag)
            printf("NO CONFLICT\n");
        else
            printf("CONFLICT\n");
    }

    return 0;
}
