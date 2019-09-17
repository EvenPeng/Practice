#include <cstdio>

using namespace std;

int main(void)
{
    int times, len, i, digit[1000000], tmpI;

    scanf("%d", &times);

    while (times-- > 0) {
        scanf("%d", &len);
        for (i = 0; i < len; ++i) {
            digit[i] = 0;
            scanf("%d", &tmpI);
            digit[i] += tmpI;
            scanf("%d", &tmpI);
            digit[i] += tmpI;
        }
        for (i = len - 1; i > 0; --i) {
            digit[i - 1] += digit[i] / 10;
            digit[i] %= 10;
        }
        for (i = 0; i < len; ++i)
            printf("%d", digit[i]);
        printf("\n");
        if (times > 0) printf("\n");
    }

    return 0;
}
