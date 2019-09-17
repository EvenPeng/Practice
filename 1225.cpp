#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int times, i, n, cnt[10001][10], tmpI;

    memset(cnt[0], 0, sizeof(int) * 10);

    for (i = 1; i < 10001; ++i) {
        memcpy(cnt[i], cnt[i - 1], sizeof(int) * 10);
        tmpI = i;
        while (tmpI > 0) {
            cnt[i][tmpI % 10]++;
            tmpI /= 10;
        }
    }

    scanf("%d", &times);

    while (times-- > 0) {
        scanf("%d", &n);
        printf("%d", cnt[n][0]);
        for (i = 1; i < 10; ++i)
            printf(" %d", cnt[n][i]);
        printf("\n");
    }

    return 0;
}
