#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Matrix {
    int n, m;
} mm[10];
int n, seq[10][10], opt[10][10];

void trace(int i, int j, int x)
{
    printf("(");
    if (i < seq[i][j] - 1)
        trace(i, seq[i][j] - 1, x + 1);
    else if (i == seq[i][j] - 1)
        printf("A%d", i + 1);
    printf(" x ");
    if (seq[i][j] < j)
        trace(seq[i][j], j, x + 1);
    else if (seq[i][j] == j)
        printf("A%d", j + 1);
    printf(")");
}

int main(void)
{
    int T = 0;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &mm[i].n, &mm[i].m);
            opt[i][i] = 0;
            seq[i][i] = i;
        }

        for (int l = 1; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                opt[i][i + l] = opt[i][i] + opt[i + 1][i + l] + mm[i].n * mm[i + 1].n * mm[i + l].m;
                seq[i][i + l] = i + 1;
                for (int j = i + 2; j <= i + l; ++j) {
                    int tmp = opt[i][j - 1] + opt[j][i + l] + mm[i].n * mm[j].n * mm[i + l].m;
                    if (tmp < opt[i][i + l]) {
                        opt[i][i + l] = tmp;
                        seq[i][i + l] = j;
                    }
                }
            }
        }

        printf("Case %d: ", ++T);
        trace(0, n - 1, 1);
        printf("\n");
    }

    return 0;
}
