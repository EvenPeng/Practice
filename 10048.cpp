#include <cstdio>
#include <cstring>

using namespace std;

inline int min(int x, int y) { return x > y ? y : x; }

inline int max(int x, int y) { return x > y ? x : y; }

int main(void)
{
    bool first;
    int  index, C, S, Q, i, j, k, u, v, d;
    int  len[101], e[101][101], map[101][101], lenQ, front, queue[10000];

    index = 0;
    first = true;
    while (true) {
        scanf("%d %d %d", &C, &S, &Q);
        if (!C && !S && !Q)
            break;
        else if (first)
            first = false;
        else
            printf("\n");
        printf("Case #%d\n", ++index);

        for (i = 1; i <= C; ++i) {
            for (j = 1; j <= C; ++j)
                map[i][j] = 0x7FFFFFFF;
            map[i][i] = 0;
        }

        for (i = 0; i < S; ++i) {
            scanf("%d %d %d", &u, &v, &d);
            map[u][v] = min(map[u][v], d);
            map[v][u] = map[u][v];
        }

        for (k = 1; k <= C; ++k)
            for (i = 1; i <= C; ++i)
                for (j = i + 1; j <= C; ++j) {
                    map[i][j] = min(map[i][j], max(map[i][k], map[k][j]));
                    map[j][i] = map[i][j];
                }

        for (i = 0; i < Q; ++i) {
            scanf("%d %d", &u, &v);
            if (map[u][v] == 0x7FFFFFFF)
                printf("no path\n");
            else
                printf("%d\n", map[u][v]);
        }
    }

    return 0;
}
