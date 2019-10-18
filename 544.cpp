#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <string>

using namespace std;

int  n, m, dist[200][200], limit[200];
bool seen[200];

int Next()
{
    int x = 0;
    while (seen[x])
        ++x;
    for (int i = x + 1; i < n; ++i)
        if (!seen[i] && limit[i] > limit[x]) x = i;

    return x;
}

int main(void)
{
    int              T, w, x, y;
    char             nA[31], nB[31];
    map<string, int> table;

    T = 0;
    while (1) {
        scanf("%d %d", &n, &m);
        if (!n && !m) break;

        table.clear();
        memset(seen, false, sizeof(seen));
        for (int i = 0; i < n; ++i)
            memset(dist[i], 0, sizeof(dist[i]));

        for (int i = 0; i < m; ++i) {
            scanf("%s %s %d", nA, nB, &w);
            if (!table[string(nA)]) table[string(nA)] = int(table.size());
            if (!table[string(nB)]) table[string(nB)] = int(table.size());
            x = table[string(nA)] - 1;
            y = table[string(nB)] - 1;
            if (w > dist[x][y]) {
                dist[x][y] = w;
                dist[y][x] = w;
            }
        }
        scanf("%s %s", nA, nB);
        x = table[string(nA)] - 1;
        y = table[string(nB)] - 1;

        seen[x] = true;
        memcpy(limit, dist[x], sizeof(limit));
        while (1) {
            x = Next();
            if (x == y) break;
            for (int i = 0; i < n; ++i)
                if (!seen[i]) limit[i] = max(limit[i], min(limit[x], dist[x][i]));
            seen[x] = true;
        }

        printf("Scenario #%d\n", ++T);
        printf("%d tons\n", limit[y]);
        printf("\n");
    }

    return 0;
}
