#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int  n, m, i, x, y, d, ans[5], cnt[1000][1000] = {0};
    int  dir[4][2]       = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    char map[1000][1000] = {'1'};

    memset(map[0], '1', sizeof(char) * 1000);
    for (i = 0; i < 1000; ++i)
        map[i][0] = '1';

    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        for (i = 1; i <= n; ++i) {
            scanf("%s", &map[i][1]);
            map[i][m + 1] = '1';
            memset(&cnt[i][1], 0, sizeof(int) * m);
        }
        memset(&map[n + 1][1], '1', sizeof(char) * m);

        x = n;
        y = 1;
        d = 0;

        do {
            cnt[x][y]++;
            for (i = 0; i < 4; ++i)
                if (map[x + dir[(i + d) % 4][0]][y + dir[(i + d) % 4][1]] == '0') {
                    x += dir[(i + d) % 4][0];
                    y += dir[(i + d) % 4][1];
                    d = (i + d - 1 + 4) % 4;
                    cnt[x][y]++;
                    break;
                }
        } while (x != n || y != 1);

        memset(ans, 0, sizeof(int) * 5);
        for (x = 1; x <= n; ++x)
            for (y = 1; y <= m; ++y)
                if (map[x][y] == '0') ans[cnt[x][y] / 2]++;

        for (i = 0; i < 5; ++i)
            printf("%3d", ans[i]);
        printf("\n");
    }

    return 0;
}
