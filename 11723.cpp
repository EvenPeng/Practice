#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int T, n, r, ans;

    T = 0;
    while (1) {
        scanf("%d %d", &r, &n);
        if (!n && !r) break;

        if (r <= n)
            ans = 0;
        else
            ans = r % n ? r / n : r / n - 1;

        if (ans <= 26)
            printf("Case %d: %d\n", ++T, ans);
        else
            printf("Case %d: impossible\n", ++T);
    }

    return 0;
}
