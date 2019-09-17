#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    long cntA[10], cntB[10], a, b, i;

    while (scanf("%ld", &i) != EOF) {
        memset(cntA, 0, sizeof(long) * 10);
        while (i) {
            cntA[i % 10]++;
            i /= 10;
        }
        memcpy(cntB, cntA, sizeof(long) * 10);

        a = 0;
        for (i = 9; i > -1; --i)
            while (cntA[i]) {
                a *= 10;
                a += i;
                cntA[i]--;
            }

        b = 0;
        for (i = 1; !cntB[i] && i < 10; ++i)
            ;
        if (i < 10) {
            b += i;
            cntB[i]--;
        }
        for (i = 0; i < 10; ++i)
            while (cntB[i]) {
                b *= 10;
                b += i;
                cntB[i]--;
            }

        printf("%ld - %ld = %ld = 9 * %ld\n", a, b, a - b, (a - b) / 9);
    }

    return 0;
}
