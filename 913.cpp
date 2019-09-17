#include <cstdio>

using namespace std;

int main(void)
{
    long n;

    while (scanf("%ld", &n) != EOF) {
        if (n == 1)
            printf("1\n");
        else {
            n = (n + 1) / 2;
            n *= n * 2;
            n--;
            printf("%ld\n", n * 3 - 6);
        }
    }

    return 0;
}
