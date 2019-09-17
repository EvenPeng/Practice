#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
    double a, b, c, r, s;

    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        if (a == 0 || b == 0 || c == 0)
            r = 0;
        else {
            s = (a + b + c) / 2;
            r = sqrt(s * (s - a) * (s - b) * (s - c)) / s;
        }
        printf("The radius of the round table is: %.3lf\n", r);
    }

    return 0;
}
