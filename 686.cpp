#include <cstdio>

using namespace std;

int main(void)
{
    bool check[32768];
    int  i, j, n, cnt, list[32768], len, beg, end;

    for (i = 0; i < 32768; ++i)
        check[i] = true;
    for (i = 2; i < 32768; ++i)
        if (check[i])
            for (j = i * 2; j < 32768; j += i)
                check[j] = false;

    len = 0;
    for (i = 2; i < 32768; ++i)
        if (check[i]) list[len++] = i;

    while (scanf("%d", &n) != EOF && n > 0) {
        cnt = 0;
        i   = 0;

        beg = 0;
        end = len;
        while (end - beg > 1) {
            j = (beg + end) / 2;
            if (list[j] > n)
                end = j;
            else if (list[j] < n)
                beg = j;
            else
                break;
        }

        while (i <= j) {
            if (list[j] + list[i] > n)
                --j;
            else if (list[j] + list[i] < n)
                ++i;
            else {
                ++cnt;
                ++i;
                --j;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
