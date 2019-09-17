#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
    double r, p;

    while (scanf("%lf %lf", &r, &p) != EOF)
        printf("%.3lf\n", p / 2 * r * r * sin(2 * M_PI / p));

    return 0;
}
