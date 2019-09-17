#include <cstdio>
#include <cstring>

using namespace std;

bool table[30][30];
int  list[30], cnt[30], len;

void route(int index, int ttl)
{
    int i;

    if (ttl < 0) return;

    for (i = 0; i < len; ++i)
        if (table[index][i] && cnt[i] < ttl) {
            cnt[i] = ttl;
            route(i, ttl - 1);
        }
}

int main(void)
{
    int n, i, j, x, y, index, indexX, indexY, beg, ttl, sum;

    index = 0;
    while (true) {
        scanf("%d", &n);
        if (n < 1) break;

        len = 0;
        memset(table, false, sizeof(char) * 900);
        for (i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            indexX = -1;
            indexY = -1;
            for (j = 0; (indexX < 0 || indexY < 0) && j < len; ++j) {
                if (list[j] == x) indexX = j;
                if (list[j] == y) indexY = j;
            }
            if (indexX < 0) {
                indexX      = len;
                list[len++] = x;
                if (x == y) indexY = indexX;
            }
            if (indexY < 0) {
                indexY      = len;
                list[len++] = y;
            }
            table[indexX][indexY] = true;
            table[indexY][indexX] = true;
        }

        while (true) {
            scanf("%d %d", &beg, &ttl);
            if (beg == 0 && ttl == 0) break;
            memset(cnt, -1, sizeof(int) * len);
            for (j = 0; j < len; ++j)
                if (list[j] == beg) break;
            cnt[j] = ttl;
            route(j, ttl - 1);
            sum = 0;
            for (j = 0; j < len; ++j)
                if (cnt[j] < 0) sum++;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++index, sum, beg, ttl);
        }
    }

    return 0;
}
