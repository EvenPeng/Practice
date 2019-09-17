#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    bool flag;
    char map[110][110], beg;
    int  times, m, n, q, i, x, y, d;

    scanf("%d", &times);

    while (times--) {
        scanf("%d %d %d", &n, &m, &q);
        printf("%d %d %d\n", n, m, q);

        for (i = 0; i < n; ++i)
            scanf("%s", &map[i][0]);

        while (q--) {
            scanf("%d %d", &x, &y);
            beg = map[x][y];

            flag = true;
            d    = 1;
            while (x - d > -1 && y - d > -1 && x + d < n && y + d < m) {
                flag &= map[x - d][y - d] == beg;
                flag &= map[x][y - d] == beg;
                flag &= map[x + d][y - d] == beg;
                flag &= map[x + d][y] == beg;
                flag &= map[x + d][y + d] == beg;
                flag &= map[x][y + d] == beg;
                flag &= map[x - d][y + d] == beg;
                flag &= map[x - d][y] == beg;
                for (i = 1; i < d && flag; ++i) {
                    flag &= map[x - i][y - d] == beg;
                    flag &= map[x + i][y - d] == beg;
                    flag &= map[x + d][y - i] == beg;
                    flag &= map[x + d][y + i] == beg;
                    flag &= map[x - i][y + d] == beg;
                    flag &= map[x + i][y + d] == beg;
                    flag &= map[x - d][y - i] == beg;
                    flag &= map[x - d][y + i] == beg;
                }
                if (flag)
                    ++d;
                else
                    break;
            }
            printf("%d\n", d * 2 - 1);
        }
    }

    return 0;
}
