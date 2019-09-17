#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    long list[14], ans;
    int  n, k;

    list[0] = 1;
    list[1] = 1;
    for (n = 2; n < 14; ++n)
        list[n] = list[n - 1] * n;

    while (scanf("%d %d", &n, &k) != EOF) {
        ans = list[n];
        while (k--) {
            scanf("%d", &n);
            ans /= list[n];
        }
        printf("%ld\n", ans);
    }

    return 0;
}
