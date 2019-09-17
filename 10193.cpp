#include <cstdio>
#include <cstring>

using namespace std;

int gcd(int x, int y)
{
    while ((x %= y) && (y %= x))
        ;

    return x > y ? x : y;
}

int main(void)
{
    char s1[33], s2[33];
    int  sum1, sum2, i, times, index;

    scanf("%d\n", &times);
    index = 0;

    while (times--) {
        scanf("%s %s", s1, s2);
        sum1 = 1;
        for (i = 1; i < strlen(s1); ++i) {
            sum1 <<= 1;
            sum1 += s1[i] == '1' ? 1 : 0;
        }
        sum2 = 1;
        for (i = 1; i < strlen(s2); ++i) {
            sum2 <<= 1;
            sum2 += s2[i] == '1' ? 1 : 0;
        }
        if (gcd(sum1, sum2) > 1)
            printf("Pair #%d: All you need is love!\n", ++index);
        else
            printf("Pair #%d: Love is not all you need!\n", ++index);
    }

    return 0;
}
