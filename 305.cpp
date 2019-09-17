#include <cstdio>
#include <cstring>

using namespace std;

bool check(int k, int m)
{
    int i, j, k2;

    k2 = k * 2;
    j  = (m - 1) % k2;

    while (j >= k) {
        j += m - k2;
        k2--;
        j %= k2;
    }

    return k2 == k;
}

int main(void)
{
    int ans[14], k, i, j;

    for (i = 1; i < 14; ++i) {
        j = i;
        while (!check(i, ++j))
            ;
        ans[i] = j;
    }

    while (true) {
        scanf("%d", &k);
        if (k < 1)
            break;
        else
            printf("%d\n", ans[k]);
    }

    return 0;
}
