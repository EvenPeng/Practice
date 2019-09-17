#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int    times, index;
    double u, v, d;

    scanf("%d", &times);
    index = 0;

    while (times--) {
        scanf("%lf %lf %lf", &d, &v, &u);
        if (v != 0 && u != 0 && u > v)
            printf("Case %d: %.3lf\n", ++index, d / sqrt(u * u - v * v) - d / u);
        else
            printf("Case %d: can't determine\n", ++index);
    }

    return 0;
}
