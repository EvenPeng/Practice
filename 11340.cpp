#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char      c[10010];
    long long map[256], sum;
    int       times, m, i, j, len;

    scanf("%d\n", &times);

    while (times--) {
        memset(map, 0, sizeof(long long) * 256);
        scanf("%d\n", &m);
        for (i = 0; i < m; ++i) {
            scanf("%s", c);
            scanf("%lld\n", &map[c[0] + 128]);
        }

        sum = 0;
        scanf("%d\n", &m);
        for (i = 0; i < m; ++i) {
            gets(c);
            len = strlen(c);
            for (j = 0; j < len; ++j)
                sum += map[c[j] + 128];
        }

        printf("%.2lf$\n", 0.01 * sum);
    }

    return 0;
}
