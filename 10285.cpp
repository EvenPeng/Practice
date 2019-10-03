#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Node {
    int x, y;
} nodes[10000];
int lenn;

int hill[102][102], ll[102][102];

bool compareNode(const Node &A, const Node &B) { return hill[A.x][A.y] > hill[B.x][B.y]; }

int main(void)
{
    int  T, R, C, ml, x, y, l;
    char name[1024];

    for (int i = 0; i < 102; ++i) {
        memset(hill[i], 0, sizeof(hill[i]));
        memset(ll[i], 0, sizeof(ll[i]));
    }

    scanf("%d", &T);
    while (T--) {
        scanf("%s %d %d", name, &R, &C);
        lenn = 0;
        for (int i = 0; i < 102; ++i) {
            memset(hill[i], 0, sizeof(hill[i]));
            memset(ll[i], 0, sizeof(ll[i]));
        }

        for (int i = 1; i <= R; ++i)
            for (int j = 1; j <= C; ++j) {
                scanf("%d", &hill[i][j]);
                nodes[lenn].x   = i;
                nodes[lenn++].y = j;
                ll[i][j]        = 1;
            }
        sort(nodes, nodes + lenn, compareNode);

        ml = 0;
        for (int i = 1; i < lenn; ++i) {
            x = nodes[i].x;
            y = nodes[i].y;
            l = ll[x][y];

            if (hill[x + 1][y] > hill[x][y]) {
                l = max(l, ll[x + 1][y] + 1);
            }
            if (hill[x - 1][y] > hill[x][y]) {
                l = max(l, ll[x - 1][y] + 1);
            }
            if (hill[x][y + 1] > hill[x][y]) {
                l = max(l, ll[x][y + 1] + 1);
            }
            if (hill[x][y - 1] > hill[x][y]) {
                l = max(l, ll[x][y - 1] + 1);
            }

            ll[x][y] = l;
            ml       = max(ml, l);
        }

        printf("%s: %d\n", name, ml);
    }

    return 0;
}
