#include <cstdio>

using namespace std;

char map[102][102];

void mark(int x, int y)
{
    int i, j;

    map[x][y] = '*';
    for (i = -1; i <= 1; ++i)
        for (j = -1; j <= 1; ++j)
            if (map[x + i][y + j] == '@') mark(x + i, y + j);
}

int main(void)
{
    int m, n, i, j, num;

    for (i = 0; i < 102; ++i) {
        map[i][0]   = '*';
        map[i][101] = '*';
        map[0][i]   = '*';
        map[101][i] = '*';
    }

    while (scanf("%d %d", &m, &n) && m > 0) {
        num = 0;
        for (i = 1; i <= m; ++i)
            scanf("%s", &map[i][1]);
        for (i = 1; i <= m; ++i)
            for (j = 1; j <= n; ++j)
                if (map[i][j] == '@') {
                    num++;
                    mark(i, j);
                }
        printf("%d\n", num);
    }

    return 0;
}
