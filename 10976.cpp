#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    bool check[10001];
    int  n, nn, i, j, cnt;

    while (scanf("%d", &n) != EOF) {
        memset(check, false, sizeof(bool) * (n + 1));

        nn  = n * n;
        cnt = 1;
        for (i = 1; i < n; ++i)
            if ((nn + i * n) % i == 0) {
                check[i] = true;
                cnt++;
            }

        printf("%d\n", cnt);
        for (i = 1; i < n; ++i)
            if (check[i]) printf("1/%d = 1/%d + 1/%d\n", n, (nn + i * n) / i, i + n);
        printf("1/%d = 1/%d + 1/%d\n", n, n * 2, n * 2);
    }

    return 0;
}
