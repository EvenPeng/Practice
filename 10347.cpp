#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    double ma, mb, mc, a, b, c, s;

    while (scanf("%lf %lf %lf", &ma, &mb, &mc) != EOF) {
        if (ma <= 0 || mb <= 0 || mc <= 0) {
            printf("-1.000\n");
            continue;
        }
        ma *= ma;
        mb *= mb;
        mc *= mc;
        a = sqrt(2 * mb + 2 * mc - ma) * 2 / 3;
        b = sqrt(2 * ma + 2 * mc - mb) * 2 / 3;
        c = sqrt(2 * ma + 2 * mb - mc) * 2 / 3;
        if (a > 0 && b > 0 && c > 0 & max(a, max(b, c)) * 2 < a + b + c) {
            s = (a + b + c) / 2;
            printf("%.3lf\n", sqrt(s * (s - a) * (s - b) * (s - c)));
        }
        else {
            printf("-1.000\n");
        }
    }

    return 0;
}
