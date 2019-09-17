#include <cstdio>
#include <cstring>

using namespace std;

long gcd(long x, long y)
{
    while ((x %= y) && (y %= x))
        ;
    return x > y ? x : y;
}

int main(void)
{
    char str[30];
    int  times, index, i;
    long cnt[128], sum;

    index = 0;
    scanf("%d", &times);

    while (times--) {
        scanf("%s", str);
        for (i = 0; i < 26; ++i)
            cnt['A' + i] = 0;
        sum = 1;
        for (i = 0; i < strlen(str); ++i) {
            cnt[str[i]]++;
            sum *= (i + 1);
            sum /= cnt[str[i]];
        }
        printf("Data set %d: %ld\n", ++index, sum);
    }

    return 0;
}
