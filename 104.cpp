#include <cstdio>
#include <cstring>

using namespace std;

struct step {
    int    pre[21][21];
    double tran[21][21];
} list[25];

int n;

int next(int y)
{
    int i, j, k, x;

    x = y - 1;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            list[y].tran[i][j] = 0;

    for (i = 1; i <= n; ++i) {
        for (k = 1; k <= n; ++k)
            if (list[x].tran[i][k] * list[0].tran[k][i] > list[y].tran[i][i]) {
                list[y].pre[i][i]  = k;
                list[y].tran[i][i] = list[x].tran[i][k] * list[0].tran[k][i];
            }
        if (list[y].tran[i][i] >= 1.01) return i;
    }

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j) {
            if (i == j) continue;
            for (k = 1; k <= n; ++k)
                if (list[x].tran[i][k] * list[0].tran[k][j] > list[y].tran[i][j]) {
                    list[y].pre[i][j]  = k;
                    list[y].tran[i][j] = list[x].tran[i][k] * list[0].tran[k][j];
                }
        }

    return 0;
}

int main(void)
{
    int i, j, x, seq[22];

    while (scanf("%d", &n) != EOF) {
        for (i = 1; i <= n; ++i)
            for (j = 1; j <= n; ++j)
                if (i ^ j)
                    scanf("%lf", &list[0].tran[i][j]);
                else
                    list[0].tran[i][j] = 1.0;

        for (i = 1; i < n; ++i) {
            x = next(i);
            if (x) break;
        }

        if (!x)
            printf("no arbitrage sequence exists\n");
        else {
            seq[i + 1] = x;
            j          = i;
            for (; i > 0; --i)
                seq[i] = list[i].pre[x][seq[i + 1]];
            printf("%d", x);
            for (i = 1; i <= j; ++i)
                printf(" %d", seq[i]);
            printf(" %d\n", x);
        }
    }

    return 0;
}
