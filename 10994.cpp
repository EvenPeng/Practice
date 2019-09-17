#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    long p, q, diff, sum, i, base;

    while (true) {
        scanf("%ld %ld", &p, &q);
        if (p < 0 && q < 0) break;
        sum = 0;

        while (q) {
            diff = q - p;
            sum += diff / 10 * 45;
            if (p % 10 > q % 10)
                for (i = p % 10; i <= q % 10 + 10; ++i)
                    sum += i % 10;
            else
                sum += (p % 10 + q % 10) * (q % 10 - p % 10 + 1) / 2;
            p = p % 10 ? p / 10 + 1 : p / 10;
            q /= 10;
            if (p > q) break;
        }

        printf("%ld\n", sum);
    }

    return 0;
}
