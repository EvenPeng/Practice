#include <cstdio>
#include <cstring>

using namespace std;

#define BASE 1000000000000000000

struct element {
    int  len;
    long digit[20];
};

int main(void)
{
    element list[1002];
    int     i, j;

    list[0].len = 1;
    memset(list[0].digit, 0, sizeof(long) * 20);
    list[0].digit[0] = 1;
    list[1].len      = 1;
    memset(list[1].digit, 0, sizeof(long) * 20);
    list[1].digit[0] = 1;
    list[2].len      = 1;
    memset(list[2].digit, 0, sizeof(long) * 20);
    list[2].digit[0] = 2;
    list[3].len      = 1;
    memset(list[3].digit, 0, sizeof(long) * 20);
    list[3].digit[0] = 3;
    list[4].len      = 1;
    memset(list[4].digit, 0, sizeof(long) * 20);
    list[4].digit[0] = 5;

    for (i = 5; i < 1002; ++i) {
        memcpy(list + i, list + i - 1, sizeof(element));
        for (j = 0; list[i].digit[j] > 0; ++j) {
            list[i].digit[j] += list[i - 2].digit[j];
            list[i].digit[j + 1] += list[i].digit[j] / BASE;
            list[i].digit[j] %= BASE;
        }
        list[i].len = j;
    }

    while (scanf("%d", &i) != EOF) {
        i++;
        printf("%ld", list[i].digit[list[i].len - 1]);
        for (j = list[i].len - 2; j > -1; --j)
            printf("%018ld", list[i].digit[j]);
        printf("\n");
    }

    return 0;
}
