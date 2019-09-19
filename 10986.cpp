#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> ll(20000, vector<pair<int, int>>(0));
vector<int>                    dis(20000), can;
vector<bool>                   seen(20000);

int T, n, m, s, d, x, y, z;

int next()
{
    int v = 0, w = dis[can[0]];

    for (int i = 1; i < can.size(); ++i)
        if (dis[can[i]] < w) {
            w = dis[can[i]];
            v = i;
        }

    w = can[v];
    can.erase(can.begin() + v);

    return w;
}

int main(void)
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d %d %d %d", &n, &m, &s, &d);
        if (s > d) swap(s, d);

        // initial
        can.clear();
        for (int i = 0; i < n; ++i) {
            ll[i].clear();
            dis[i]  = 20000001;
            seen[i] = false;
            can.push_back(i);
        }

        for (int k = 0; k < m; ++k) {
            scanf("%d %d %d", &x, &y, &z);
            ll[x].push_back(make_pair(y, z));
            ll[y].push_back(make_pair(x, z));
        }

        if (s == d) {
            printf("Case #%d: %d\n", t, 0);
            continue;
        }

        dis[s] = 0;
        while (!can.empty()) {
            x       = next();
            seen[x] = true;
            for (int i = 0; i < ll[x].size(); ++i) {
                y = ll[x][i].first;
                if (!seen[y]) dis[y] = min(dis[y], dis[x] + ll[x][i].second);
            }

            if (x == d) break;
        }

        if (dis[d] < 20000001)
            printf("Case #%d: %d\n", t, dis[d]);
        else
            printf("Case #%d: unreachable\n", t);
    }

    return 0;
}
