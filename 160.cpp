#include <cstdio>

using namespace std;

int main(void)
{
    bool check[101];
    int  i, j, lenP, prime[50], cnt[101][30], tmpInt;

    for (i = 2; i < 101; ++i)
        check[i] = true;

    for (i = 2; i < 101; ++i)
        if (check[i])
            for (j = i + i; j < 101; j += i)
                check[j] = false;

    lenP = 0;
    for (i = 2; i < 101; ++i)
        if (check[i]) prime[lenP++] = i;

    cnt[2][0] = 1;
    for (j = 1; j < lenP; ++j)
        cnt[2][j] = 0;
    for (i = 3; i < 101; ++i) {
        for (j = 0; j < lenP; ++j)
            cnt[i][j] = cnt[i - 1][j];
        tmpInt = i;
        j      = 0;
        while (tmpInt > 1) {
            if (tmpInt % prime[j])
                j++;
            else {
                cnt[i][j]++;
                tmpInt /= prime[j];
            }
        }
    }

    while (scanf("%d", &tmpInt) != EOF && tmpInt > 0) {
        printf("%3d! =", tmpInt);
        i = 0;
        while (i < 15 && prime[i] <= tmpInt)
            printf("%3d", cnt[tmpInt][i++]);
        if (prime[i] <= tmpInt) printf("\n      ");
        while (i < lenP && prime[i] <= tmpInt)
            printf("%3d", cnt[tmpInt][i++]);
        printf("\n");
    }

    return 0;
}
