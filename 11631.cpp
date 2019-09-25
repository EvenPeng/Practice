#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int root[200000];
struct Road {
    int s, d, w;
} ll[200000];

bool compareRoad(Road x, Road y) { return x.w != y.w ? x.w < y.w : (x.s != y.s ? x.s < y.s : x.d < y.d); }

int getRoot(int x)
{
    while (x != root[x])
        x = root[x];
    return x;
}

int main(void)
{
    int n, m, save;

    while (1) {
        scanf("%d %d", &n, &m);
        if (!n && !m) break;

        for (int i = 0; i < m; ++i)
            scanf("%d %d %d", &ll[i].s, &ll[i].d, &ll[i].w);

        sort(ll, ll + m, compareRoad);

        save = 0;
        for (int i = 0; i < n; ++i)
            root[i] = i;
        for (int i = 0; i < m; ++i) {
            int ra = getRoot(ll[i].s);
            int rb = getRoot(ll[i].d);
            if (ra == rb)
                save += ll[i].w;
            else if (ra < rb) {
                root[rb]      = ra;
                root[ll[i].s] = ra;
                root[ll[i].d] = ra;
            }
            else {
                root[ra]      = rb;
                root[ll[i].s] = rb;
                root[ll[i].d] = rb;
            }
        }

        printf("%d\n", save);
    }

    return 0;
}
