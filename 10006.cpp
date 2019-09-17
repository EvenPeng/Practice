#include <cstdio>

using namespace std;

unsigned int check(unsigned int base, unsigned int power, unsigned int divid)
{
    unsigned int left;

    base %= divid;
    if (power == 1)
        left = base;
    else if (power == 2)
        left = (base * base) % divid;
    else if (power % 2)
        left = (check(base, power - 1, divid) * base) % divid;
    else
        left = (check(base * base, power / 2, divid)) % divid;

    return left;
}

int main(void)
{
    bool         arr[65000], flag;
    unsigned int n, i, len, list[32500], beg, end;

    for (i = 2; i < 65000; ++i)
        arr[i] = true;
    for (i = 2; i < 65000; ++i)
        if (arr[i])
            for (n = 2 * i; n < 65000; n += i)
                arr[n] = false;

    len = 0;
    for (i = 2; i < 65000; ++i)
        if (arr[i]) list[len++] = i;

    while (scanf("%d", &n) != EOF) {
        if (n < 1) break;

        beg = 0;
        end = len;
        while (end - beg > 1) {
            i = (beg + end) / 2;
            if (list[i] > n)
                end = i;
            else if (list[i] < n)
                beg = i;
            else
                break;
        }

        flag = list[i] != n;
        for (i = 2; flag && i < n; ++i)
            if (check(i, n, n) != i) flag = false;

        if (flag)
            printf("The number %d is a Carmichael number.\n", n);
        else
            printf("%d is normal.\n", n);
    }

    return 0;
}
