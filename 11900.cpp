#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int T, n, p, q, w, cnt, sum;

    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d %d %d", &n, &p, &q);
        cnt = 0;
        sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &w);
            if (w <= q && cnt < p && w + sum <= q) {
                cnt++;
                sum += w;
            }
        }

        printf("Case %d: %d\n", t, cnt);
    }

    return 0;
}
