#include <cstdio>

using namespace std;

int main(void)
{
    int org[21], judge[21], table[21][21], pos, len, i, j;

    scanf("%d", &len);

    for (i = 0; i < len; ++i) {
        scanf("%d", &pos);
        org[pos - 1] = i;
    }

    while (scanf("%d", &pos) != EOF) {
        judge[pos - 1] = 0;
        for (i = 1; i < len; ++i) {
            scanf("%d", &pos);
            judge[pos - 1] = i;
        }

        table[0][0] = org[0] == judge[0] ? 1 : 0;
        for (i = 1; i < len; ++i) {
            table[i][0] = table[i - 1][0] || org[i] == judge[0] ? 1 : 0;
            table[0][i] = table[0][i - 1] || org[0] == judge[i] ? 1 : 0;
        }

        for (i = 1; i < len; ++i)
            for (j = 1; j < len; ++j)
                if (org[i] == judge[j])
                    table[i][j] = table[i - 1][j - 1] + 1;
                else
                    table[i][j] = table[i][j - 1] > table[i - 1][j] ? table[i][j - 1] : table[i - 1][j];

        printf("%d\n", table[len - 1][len - 1]);
    }

    return 0;
}
