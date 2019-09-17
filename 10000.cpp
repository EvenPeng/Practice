#include <cstdio>
#include <cstring>

using namespace std;

struct node {
    int l, v[101];
};

int main(void)
{
    bool table[101];
    int  n, s, i, j, u, v, max[101], queue[101], rear, lenQ, index;
    node list[101];

    index = 0;
    while (true) {
        scanf("%d", &n);
        if (!n) break;

        for (i = 0; i <= n; ++i)
            list[i].l = 0;
        memset(max, 0, sizeof(int) * (n + 1));
        memset(table, true, sizeof(bool) * (n + 1));
        scanf("%d", &s);
        while (true) {
            scanf("%d %d", &u, &v);
            if (!u && !v) break;
            list[u].v[list[u].l++] = v;
        }

        queue[0] = s;
        rear     = 0;
        lenQ     = 1;
        while (lenQ) {
            u        = queue[rear];
            table[u] = true;
            rear     = (rear + 1) % 100;
            lenQ--;
            for (i = 0; i < list[u].l; ++i) {
                v = list[u].v[i];
                if (max[v] < max[u] + 1) {
                    max[v] = max[u] + 1;
                    if (table[v]) {
                        table[v]                   = false;
                        queue[(rear + lenQ) % 100] = v;
                        lenQ++;
                    }
                }
            }
        }

        u = 1;
        for (i = 2; i <= n; ++i)
            if (max[i] > max[u]) u = i;

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++index, s, max[u], u);
    }

    return 0;
}
