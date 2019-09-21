#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
    int         n, m, cnt, x;
    vector<int> ll(1000000);

    while (1) {
        scanf("%d %d\n", &n, &m);
        if (n == 0 && m == 0) break;
        cnt = 0;

        for (int i = 0; i < n; ++i)
            scanf("%d", &ll[i]);

        int i = 0;
        for (int j = 0; j < m; ++j) {
            scanf("%d", &x);
            while (i < n && ll[i] <= x) {
                if (ll[i] == x) cnt++;
                ++i;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
