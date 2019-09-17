#include <cstdio>
#include <cstring>

using namespace std;

#define BASE 1000000000000000

int sum[1001];

int main(void)
{
    int  len, i, j, n;
    long list[1000], tmpL;

    memset(sum, 0, sizeof(int) * 1001);
    memset(list, 0, sizeof(long) * 1000);
    sum[0] = 0;
    sum[1] = 1;
    sum[2] = 2;
    sum[3] = 6;

    list[0] = 6;
    len     = 1;

    for (i = 4; i < 1001; ++i) {
        for (j = 0; j < len; ++j)
            list[j] *= i;
        for (j = 0; j < len; ++j) {
            list[j + 1] += list[j] / BASE;
            list[j] %= BASE;
        }
        while (list[len] > 0)
            ++len;
        for (j = 0; j < len; ++j) {
            tmpL = list[j];
            while (tmpL > 0) {
                sum[i] += tmpL % 10;
                tmpL /= 10;
            }
        }
    }

    while (scanf("%d", &n) != EOF)
        printf("%d\n", sum[n]);

    return 0;
}
