#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int    T;
    long   x;
    double n;
    scanf("%d", &T);
    while (T--) {
        scanf("%ld", &x);
        n = floor((sqrt((double)x * 8 + 1) - 1) / 2);
        printf("%.0lf\n", n);
    }

    return 0;
}
