#include <cstdio>
#include <cstring>

using namespace std;

char map[1002][1002], c;
int  cnt[26];

static inline int cmp(int x, int y) { return cnt[x] == cnt[y] ? y - x : cnt[x] - cnt[y]; }

void sortL(int *list, int len)
{
    int i = 0;
    int j = len - 1;
    int tmpS, pivot = list[len / 2];

    if (len < 2) return;

    while (true) {
        while (cmp(list[i], pivot) > 0)
            ++i;
        while (cmp(list[j], pivot) < 0)
            --j;
        if (i >= j) break;

        tmpS    = list[i];
        list[i] = list[j];
        list[j] = tmpS;
    }

    sortL(list, i);
    sortL(list + i, len - i);
}

void explore(int x, int y)
{
    if (map[x + 1][y] == c) {
        map[x + 1][y] = -1;
        explore(x + 1, y);
    }
    if (map[x][y + 1] == c) {
        map[x][y + 1] = -1;
        explore(x, y + 1);
    }
    if (map[x - 1][y] == c) {
        map[x - 1][y] = -1;
        explore(x - 1, y);
    }
    if (map[x][y - 1] == c) {
        map[x][y - 1] = -1;
        explore(x, y - 1);
    }
}

int main(void)
{
    int times, index, table[128], list[26], len, i, j, m, n;

    for (i = 0; i < 26; ++i)
        table['a' + i] = i;
    for (j = 0; j < 1002; ++j) {
        map[0][j] = -1;
        map[j][0] = -1;
    }
    index = 0;
    scanf("%d", &times);

    while (times--) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d %d", &n, &m);
        for (j = 1; j < m + 2; ++j)
            map[n + 1][j] = -1;
        for (i = 1; i <= n; ++i) {
            scanf("%s", &map[i][1]);
            map[i][0]     = -1;
            map[i][m + 1] = -1;
        }
        printf("World #%d\n", ++index);
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= m; ++j)
                if (map[i][j] != -1) {
                    c         = map[i][j];
                    map[i][j] = -1;
                    cnt[table[c]]++;
                    explore(i, j);
                }
        len = 0;
        for (i = 0; i < 26; ++i)
            if (cnt[i]) list[len++] = i;
        sortL(list, len);
        for (i = 0; i < len; ++i)
            printf("%c: %d\n", list[i] + 'a', cnt[list[i]]);
    }

    return 0;
}
