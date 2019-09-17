#include <cstdio>
#include <cstring>

using namespace std;

int map[101][101], max;

void explore(int x, int y)
{
    bool flag;
    int  xmax, ymax, i, j, n, m, area;

    max = max == 0 ? 1 : max;

    xmax = 1;
    while (map[x + xmax][y] == 0)
        ++xmax;
    ymax = 1;
    while (map[x][y + ymax] == 0)
        ++ymax;
    if (xmax * ymax < max) return;

    area = xmax > ymax ? xmax : ymax;
    for (i = xmax - 1; i > 0; --i)
        for (j = ymax - 1; j > 0; --j) {
            if ((i + 1) * (j + 1) < area) break;
            if (!map[x + i][y + j]) {
                flag = true;
                for (n = x + i; n > x && flag; --n)
                    for (m = y + j; m > y && flag; --m)
                        flag &= map[n][m] == 0;
                if (flag) area = (i + 1) * (j + 1);
            }
        }

    if (area > max) max = area;
}

int main(void)
{
    int i, j, n, m;

    while (true) {
        scanf("%d %d", &n, &m);
        if (!m && !n) break;

        for (i = 0; i < n; ++i)
            for (j = 0; j < m; ++j)
                scanf("%d", &map[i][j]);

        for (i = 0; i < n; ++i)
            map[i][m] = 1;
        for (i = 0; i < m; ++i)
            map[n][i] = 1;
        map[n][m] = 1;

        max = 0;
        for (i = 0; i < n; ++i)
            for (j = 0; j < m; ++j) {
                if ((n - i) * (m - j) <= max)
                    break;
                else if (!map[i][j])
                    explore(i, j);
            }

        printf("%d\n", max);
    }

    return 0;
}
