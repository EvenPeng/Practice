#include <cmath>
#include <cstdio>

using namespace std;

int len, prime[100000];

static inline void gen(int x)
{
    bool flag;
    int  i, bound, tmpI;

    tmpI = prime[len - 1];
    while (prime[len - 1] <= x) {
        tmpI += 2;
        flag  = true;
        bound = (int)sqrt((double)tmpI);
        for (i = 0; flag && prime[i] <= bound; ++i)
            if (tmpI % prime[i] == 0) flag = false;
        if (flag) prime[len++] = tmpI;
    }
}

static inline bool isPrime(int x)
{
    int bound = (int)sqrt((double)x);
    int i     = 0;

    if (prime[len - 1] <= bound) gen(bound);

    while (prime[i] <= bound)
        if (x % prime[i++] == 0) return false;

    return true;
}

static inline int gcd(int x, int y)
{
    while ((x %= y) > 0 && (y %= x) > 0)
        ;
    return x > y ? x : y;
}

int main(void)
{
    int n, lenP, lenO, lenT, listP[51], listO[51], listT[51], i, j, cnt, tmpI;

    len      = 4;
    prime[0] = 3;
    prime[1] = 5;
    prime[2] = 7;
    prime[3] = 11;

    while (true) {
        scanf("%d", &n);
        if (n == 0) break;

        lenP = 0;
        lenO = 0;
        lenT = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d", &tmpI);
            if (tmpI % 2 == 0)
                listT[lenT++] = tmpI;
            else if (isPrime(tmpI))
                listP[lenP++] = tmpI;
            else
                listO[lenO++] = tmpI;
        }

        cnt = 0;
        for (i = 0; i < lenO; ++i) {
            for (j = 0; j < lenT; ++j)
                if (gcd(listO[i], listT[j]) < 2) cnt++;
            for (j = i + 1; j < lenO; ++j)
                if (gcd(listO[i], listO[j]) < 2) cnt++;
        }

        for (i = 0; i < lenP; ++i) {
            if (listP[i] == 1)
                cnt += lenT + lenO;
            else {
                for (j = 0; j < lenT; ++j)
                    if (listT[j] % listP[i] != 0) cnt++;
                for (j = 0; j < lenO; ++j)
                    if (listO[j] % listP[i] != 0) cnt++;
            }
            for (j = i + 1; j < lenP; ++j)
                if (listP[i] != listP[j]) cnt++;
        }

        if (cnt > 0)
            printf("%f\n", sqrt((3.0 * n * (n - 1)) / (float)cnt));
        else
            printf("No estimate for this data set.\n");
    }

    return 0;
}
