#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int times, left, tmpI, base, sum;

    scanf("%d", &times);

    while (times-- > 0) {
        scanf("%d %d %d", &left, &tmpI, &base);
        left += tmpI;
        sum = 0;
        while (left >= base) {
            tmpI = left / base;
            sum += tmpI;
            left %= base;
            left += tmpI;
        }
        printf("%d\n", sum);
    }

    return 0;
}
