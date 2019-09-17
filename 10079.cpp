#include <cstdio>

using namespace std;

int main(void)
{
    long n;

    while (scanf("%ld", &n) != EOF && n > -1)
        if (n == 0)
            printf("1\n");
        else
            printf("%ld\n", 1 + (1 + n) * n / 2);

    return 0;
}
