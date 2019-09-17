#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct elem {
    int  v, l;
    bool operator<(elem other) const
    {
        if (v == other.v)
            return l < other.l;
        else
            return v < other.v;
    }
} list[1000001];

int head[1000001], len[1000001];

int main(void)
{
    int n, m, i, j;

    while (scanf("%d %d", &n, &m) != EOF) {
        memset(len, 0, sizeof(int) * 1000001);
        for (i = 0; i < n; ++i) {
            scanf("%d", &list[i].v);
            list[i].l = i;
            len[list[i].v]++;
        }

        sort(list, list + n);

        for (i = 0; i < n;) {
            head[list[i].v] = i;
            i += len[list[i].v];
        }

        while (m--) {
            scanf("%d %d", &i, &j);
            if (len[j] >= i)
                printf("%d\n", list[head[j] + i - 1].l + 1);
            else
                printf("0\n");
        }
    }

    return 0;
}
