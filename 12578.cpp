#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    double cR, cG, L;
    int    times;

    cR = 0.04 * M_PI;
    cG = 0.6 - cR;

    scanf("%d\n", &times);
    while (times--) {
        scanf("%lf", &L);
        L *= L;
        printf("%.2lf %.2lf\n", L * cR, L * cG);
    }

    return 0;
}
