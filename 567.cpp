#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int len[21], e[21][21], lenQ, front, queue[21], step[21];
    int n, i, j, u, v, index, curr, min;

    index = 0;
    while (scanf("%d", &n) != EOF) {
        memset(len, 0, sizeof(int) * 21);
        for (i = 1; i < 20; ++i) {
            for (j = 0; j < n; ++j) {
                scanf("%d", &v);
                e[i][len[i]++] = v;
                e[v][len[v]++] = i;
            }
            scanf("%d", &n);
        }

        printf("Test Set #%d\n", ++index);

        for (i = 0; i < n; ++i) {
            for (j = 0; j < 21; ++j)
                step[j] = -1;
            scanf("%d %d", &u, &v);
            if (u == v)
                min = 0;
            else {
                front    = 0;
                lenQ     = 1;
                queue[0] = u;
                step[u]  = 0;
                while (lenQ) {
                    curr = queue[front++];
                    lenQ--;
                    for (j = 0; j < len[curr]; ++j)
                        if (step[e[curr][j]] < 0) {
                            if (e[curr][j] == v) {
                                min  = step[curr] + 1;
                                lenQ = 0;
                                break;
                            }
                            else {
                                step[e[curr][j]]    = step[curr] + 1;
                                queue[front + lenQ] = e[curr][j];
                                lenQ++;
                            }
                        }
                }
            }
            printf("%2d to %2d: %d\n", u, v, min);
        }

        printf("\n");
    }

    return 0;
}
