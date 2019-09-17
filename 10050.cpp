#include <cstdio>

using namespace std;

int main(void)
{
    int times, days, len, P[100], sum, i, j;

    scanf("%d", &times);

    while (times-- > 0) {
        scanf("%d %d", &days, &len);
        for (j = 0; j < len; ++j)
            scanf("%d", P + j);

        sum = 0;
        for (i = 1; i <= days; ++i) {
            if (i % 7 == 6 || i % 7 == 0) continue;
            for (j = 0; j < len; ++j)
                if (i % P[j] == 0) {
                    sum++;
                    break;
                }
        }

        printf("%d\n", sum);
    }

    return 0;
}
