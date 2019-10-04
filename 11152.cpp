#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

#define PI 3.14159265359

int main(void)
{
    double a, b, c, s, ia, ta, oa;

    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        s  = (a + b + c) / 2;
        ta = sqrt(s * (s - a) * (s - b) * (s - c));
        ia = (s - a) * (s - b) * (s - c) * PI / s;
        oa = PI * a * a * b * b * c * c / ((a + b + c) * (a + b - c) * (a + c - b) * (b + c - a));
        oa -= ta;
        ta -= ia;
        printf("%.4lf %.4lf %.4lf\n", oa, ta, ia);
    }

    return 0;
}
