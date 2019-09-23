#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int                 num;
bool                seen[50000];
vector<vector<int>> ll(50000, vector<int>(0));

void travel(int x)
{
    for (int i = 0; i < ll[x].size(); ++i)
        if (!seen[ll[x][i]]) {
            seen[ll[x][i]] = true;
            num--;
            travel(ll[x][i]);
        }
}

int main(void)
{
    int T, n, m, ans, x, y;

    T = 0;
    while (1) {
        scanf("%d %d", &n, &m);
        if (!n && !m) break;

        memset(seen, false, sizeof(seen));
        for (int i = 0; i < n; ++i)
            ll[i].clear();

        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &x, &y);
            if (x == y) continue;
            x--;
            y--;
            ll[x].push_back(y);
            ll[y].push_back(x);
        }

        ans = 0;
        num = n;
        while (num > 0) {
            for (int i = 0; i < n; ++i)
                if (!seen[i]) {
                    seen[i] = true;
                    ans++;
                    num--;
                    travel(i);
                }
        }

        printf("Case %d: %d\n", ++T, ans);
    }
    return 0;
}
