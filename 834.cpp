#include <cstdio>

using namespace std;

int gcd(int x, int y)
{
    while (x != 0 && y != 0) {
        if (x > y)
            x %= y;
        else if (y > x)
            y %= x;
        else
            return x;
    }

    return x > y ? x : y;
}

void cal(int x, int y)
{
    printf("%d,", x / y);
    x %= y;
    if (x > 1)
        cal(y, x);
    else
        printf("%d", y);
}

int main(void)
{
    int x, y, comm;

    while (scanf("%d %d", &x, &y) != EOF) {
        printf("[%d", x / y);
        x %= y;
        if (x == 0) {
            printf("]\n");
            continue;
        }
        else
            printf(";");
        comm = gcd(x, y);
        x /= comm;
        y /= comm;
        if (x > 1)
            cal(y, x);
        else
            printf("%d", y);
        printf("]\n");
    }

    return 0;
}
