#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct elem {
    int  r, c, v;
    bool operator<(elem other) const { return r != other.r ? r < other.r : c < other.c; }
} list[1001];

int main(void)
{
    int n, m, i, j, l, len, num[10001];

    while (scanf("%d %d", &m, &n) != EOF) {
        len = 0;
        l   = n > m ? n : m;
        memset(num, 0, sizeof(int) * (l + 1));

        for (i = 1; i <= m; ++i) {
            scanf("%d", &l);

            for (j = 0; j < l; ++j) {
                scanf("%d", &list[len + j].r);
                list[len + j].c = i;
                num[list[len + j].r]++;
            }
            for (j = 0; j < l; ++j)
                scanf("%d", &list[len + j].v);

            len += l;
        }

        sort(list, list + len);

        printf("%d %d\n", n, m);
        l = 0;
        for (i = 1; i <= n; ++i) {
            printf("%d", num[i]);
            for (j = 0; j < num[i]; ++j)
                printf(" %d", list[l + j].c);
            printf("\n");
            if (num[i]) printf("%d", list[l].v);
            for (j = 1; j < num[i]; ++j)
                printf(" %d", list[l + j].v);
            printf("\n");
            l += num[i];
        }
    }

    return 0;
}
