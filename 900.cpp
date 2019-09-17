#include <cstdio>

using namespace std;

long brick[51];
long C[51][51];

void cnt(int x)
{
    int  h   = x;
    int  v   = 0;
    long sum = 1;

    while (h > 1) {
        h -= 2;
        v++;
        if (h > v)
            sum += C[h + v][v];
        else
            sum += C[h + v][h];
    }

    brick[x] = sum;
}

int main(void)
{
    int n, i, j;

    brick[0] = 1;
    brick[1] = 1;
    brick[2] = 2;
    for (i = 3; i < 51; ++i)
        brick[i] = 0;
    for (i = 1; i < 51; ++i) {
        C[i][0] = 1;
        C[i][1] = i;
        for (j = 2; j <= i; ++j)
            if (j <= i - j)
                C[i][j] = C[i][j - 1] * (i - j + 1) / j;
            else
                C[i][j] = C[i][i - j];
    }

    while (true) {
        scanf("%d", &n);
        if (n < 1) break;

        if (brick[n] < 1) cnt(n);
        printf("%ld\n", brick[n]);
    }

    return 0;
}
