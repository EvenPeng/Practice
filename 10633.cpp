#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    bool               first;
    unsigned long long n, m, i;

    while (true) {
        scanf("%lld", &n);
        if (!n) break;
        m     = (n * 10) / 9;
        first = true;
        for (i = m - 1; i <= m + 1; ++i) {
            if (i - (i / 10) == n) {
                if (first) {
                    printf("%lld", i);
                    first = false;
                }
                else
                    printf(" %lld", i);
            }
        }
        printf("\n");
    }

    return 0;
}
