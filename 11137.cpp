#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

long units[22], cnt[10001];

int main(void)
{
    int i, j, k;

    for (i = 1; i < 22; ++i)
        units[i] = (long)pow(i, 3);
    for (i = 0; i < 10001; ++i)
        cnt[i] = 1;

    for (i = 2; i < 22; ++i)
        for (j = units[i], k = 0; j < 10001; ++j, ++k)
            cnt[j] += cnt[k];

    while (scanf("%d", &i) != EOF)
        printf("%ld\n", cnt[i]);

    return 0;
}
