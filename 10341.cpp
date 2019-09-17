#include <cmath>
#include <cstdio>

using namespace std;

int p, q, r, s, t, u;

double f(double x) { return p * exp(-1 * x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u; }

double fd(double x) { return -1 * p * exp(-1 * x) + q * cos(x) - r * sin(x) + s / pow(cos(x), 2) + 2 * t * x; }

int main(void)
{
    double x, x1;
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
        if (f(0) * f(1) > 0) {
            printf("No solution\n");
            continue;
        }
        else {
            if (f(0) == 0)
                x1 = 0;
            else {
                x = 0.5;
                while (true) {
                    x1 = x - f(x) / fd(x);
                    if (fabs(x1 - x) < 1.0e-8) break;
                    x = x1;
                }
            }
            printf("%.4lf\n", x1);
        }
    }
}
