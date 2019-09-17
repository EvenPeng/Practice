#include <cstdio>

using namespace std;

int main(void)
{
    bool check[1001];
    int  n, c, i, j, len, list[1001], cnt[1001], beg, end;

    for (i = 1; i < 1001; ++i)
        check[i] = true;
    for (i = 2; i < 1001; ++i)
        if (check[i])
            for (j = 2 * i; j < 1001; j += i)
                check[j] = false;

    len = 0;
    for (i = 1; i < 1001; ++i) {
        if (check[i]) list[len++] = i;
        cnt[i] = len;
    }

    while (scanf("%d %d", &n, &c) != EOF) {
        if (c * 2 < cnt[n]) {
            beg = cnt[n] / 2 - c + cnt[n] % 2;
            end = cnt[n] / 2 + c - 1;
        }
        else {
            beg = 0;
            end = cnt[n] - 1;
        }
        printf("%d %d: ", n, c);
        for (; beg < end; ++beg)
            printf("%d ", list[beg]);
        printf("%d\n\n", list[end]);
    }

    return 0;
}
