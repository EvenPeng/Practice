#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int T, M, C;
int germ[20][20];
int leng[20], mm[20];

int comb(int x, int m)
{
    int i = int(upper_bound(germ[x], germ[x] + leng[x], m - mm[x]) - germ[x]);
    if (x == C - 1) return germ[x][i - 1];

    int v = 0;
    for (--i; v < m && i > -1; --i)
        v = max(v, germ[x][i] + comb(x + 1, m - germ[x][i]));

    return v;
}

int main(void)
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &M, &C);
        for (int i = 0; i < C; ++i) {
            scanf("%d", leng + i);
            for (int j = 0; j < leng[i]; ++j)
                scanf("%d", germ[i] + j);

            sort(germ[i], germ[i] + leng[i]);
            leng[i] = int(unique(germ[i], germ[i] + leng[i]) - germ[i]);
        }

        mm[C - 1] = 0;
        for (int i = C - 2; i > -1; --i)
            mm[i] = mm[i + 1] + germ[i + 1][0];

        if (mm[0] + germ[0][0] > M)
            printf("no solution\n");
        else {
            printf("%d\n", comb(0, M));
        }
    }

    return 0;
}
