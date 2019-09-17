#include <algorithm>
#include <cstdio>

using namespace std;

int cut[55], dp[55][55];

int find(int beg, int end)
{
    int i, sum;

    if (dp[beg][end] == -1) {
        sum = min(find(beg + 1, end), find(beg, end - 1));
        for (i = beg + 1; i < end; ++i)
            sum = min(sum, find(beg, i - 1) + find(i + 1, end));
        dp[beg][end] = sum + cut[end + 1] - cut[beg - 1];
    }

    return dp[beg][end];
}

int main(void)
{
    int len, n, i, j;

    while (scanf("%d", &len) != EOF) {
        if (len < 1) break;

        scanf("%d", &n);
        cut[0]     = 0;
        cut[n + 1] = len;
        for (i = 1; i <= n; ++i)
            scanf("%d", cut + i);
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= n; ++j)
                dp[i][j] = -1;
            dp[i][i] = cut[i + 1] - cut[i - 1];
        }

        printf("The minimum cutting is %d.\n", find(1, n));
    }

    return 0;
}
