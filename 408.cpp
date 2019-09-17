#include <cstdio>

using namespace std;

int gcd(int x, int y)
{
    while (x > 0 && y > 0) {
        if (x > y)
            x %= y;
        else if (y > x)
            y %= x;
        else
            return x;
    }

    return x > y ? x : y;
}

int main(void)
{
    int s, m;

    while (scanf("%d %d", &s, &m) != EOF) {
        printf("%10d%10d    ", s, m);
        if (gcd(s, m) == 1)
            printf("Good Choice\n\n");
        else
            printf("Bad Choice\n\n");
    }

    return 0;
}
