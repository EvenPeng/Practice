#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int R, C, land[1000][1000];
int xr, yr, xd, yd;
struct pos {
    int x, y;
};

int main(void)
{
    int x, y, n, m;
    while (1) {
        scanf("%d %d", &R, &C);
        if (!R && !C) break;

        for (int i = 0; i < R; ++i)
            memset(land[i], 0, sizeof(land[i]));

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &x, &m);
            for (int j = 0; j < m; ++j) {
                scanf("%d", &y);
                land[x][y] = -1;
            }
        }

        scanf("%d %d\n", &xr, &yr);
        scanf("%d %d\n", &xd, &yd);
        land[xr][yr] = 1;
        queue<pos> q;
        q.push({xr, yr});

        pos cur;
        while (q.size()) {
            cur = q.front();
            if (cur.x == xd && cur.y == yd) break;
            q.pop();
            if (cur.x + 1 < R && !land[cur.x + 1][cur.y]) {
                land[cur.x + 1][cur.y] = land[cur.x][cur.y] + 1;
                q.push({cur.x + 1, cur.y});
            }
            if (cur.y + 1 < C && !land[cur.x][cur.y + 1]) {
                land[cur.x][cur.y + 1] = land[cur.x][cur.y] + 1;
                q.push({cur.x, cur.y + 1});
            }
            if (cur.x - 1 > -1 && !land[cur.x - 1][cur.y]) {
                land[cur.x - 1][cur.y] = land[cur.x][cur.y] + 1;
                q.push({cur.x - 1, cur.y});
            }
            if (cur.y - 1 > -1 && !land[cur.x][cur.y - 1]) {
                land[cur.x][cur.y - 1] = land[cur.x][cur.y] + 1;
                q.push({cur.x, cur.y - 1});
            }
        }

        printf("%d\n", land[xd][yd] - 1);
    }

    return 0;
}
