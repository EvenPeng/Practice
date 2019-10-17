#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

double dist(double xa, double ya, double xb, double yb)
{
    double x = xa - xb;
    double y = ya - yb;
    return sqrt(x * x + y * y);
}

int main(void)
{
    int    n;
    double gx, gy, gd, dx, dy, dd, x, y, ex, ey;
    bool   esp;

    while (scanf("%d", &n) != EOF) {
        scanf("%lf %lf %lf %lf", &gx, &gy, &dx, &dy);
        esp = false;

        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf", &x, &y);
            if (!esp) {
                gd = dist(gx, gy, x, y);
                dd = dist(dx, dy, x, y);
                if (gd * 2 <= dd) {
                    esp = true;
                    ex  = x;
                    ey  = y;
                }
            }
        }

        if (esp)
            printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", ex, ey);
        else
            printf("The gopher cannot escape.\n");
    }

    return 0;
}
