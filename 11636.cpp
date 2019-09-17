#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
    int    n, index;
    double out, base;

    base  = log(2);
    index = 0;

    while (scanf("%d", &n) != EOF && n > 0) {
        out = (double)n;
        out = ceil(log(out) / base);
        printf("Case %d: %.0f\n", ++index, out);
    }

    return 0;
}
