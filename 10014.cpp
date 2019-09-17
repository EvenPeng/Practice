#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int    times, n, i;
    double a1, a0, an, c;

    scanf("%d", &times);

    while (times--) {
        scanf("%d %lf %lf", &n, &a0, &an);
        a1 = a0 * n + an;
        for (i = n * 2; i > 0; i -= 2) {
            scanf("%lf", &c);
            a1 -= c * i;
        }
        if (times)
            printf("%.2lf\n\n", a1 / (n + 1));
        else
            printf("%.2lf\n", a1 / (n + 1));
    }

    return 0;
}
