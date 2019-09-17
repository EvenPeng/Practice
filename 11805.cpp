#include <cstdio>

using namespace std;

int main(void)
{
    int times, index, n, k, p;

    scanf("%d", &times);
    index = 0;

    while (times-- > 0) {
        scanf("%d %d %d", &n, &k, &p);
        printf("Case %d: %d\n", ++index, (k + p - 1) % n + 1);
    }

    return 0;
}
