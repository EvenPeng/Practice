#include <cstdio>

using namespace std;

int main(void)
{
    int len, table[101][101], i, j, cntR, cntC;

    while (scanf("%d", &len) != EOF && len > 0) {
        for (i = 0; i < len; ++i) {
            table[len][i] = 0;
            table[i][len] = 0;
        }

        for (i = 0; i < len; ++i)
            for (j = 0; j < len; ++j) {
                scanf("%d", &table[i][j]);
                table[i][len] += table[i][j];
                table[len][j] += table[i][j];
            }

        cntR = 0;
        cntC = 0;
        for (i = 0; i < len; ++i) {
            cntR += table[i][len] % 2;
            cntC += table[len][i] % 2;
        }

        if (cntR + cntC == 0)
            printf("OK\n");
        else if (cntR > 1 || cntC > 1)
            printf("Corrupt\n");
        else {
            printf("Change bit (");
            for (i = 0; i < len; ++i)
                if (table[i][len] % 2) {
                    printf("%d,", i + 1);
                    break;
                }
            for (i = 0; i < len; ++i)
                if (table[len][i] % 2) {
                    printf("%d)\n", i + 1);
                    break;
                }
        }
    }

    return 0;
}
