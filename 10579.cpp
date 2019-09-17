#include <cstdio>
#include <cstring>

using namespace std;

#define BASE 10000000000L

struct elem {
    int  len;
    long digit[102];
};

elem list[100000];

static inline void add(int x)
{
    int i;

    memcpy(list + x, list + x - 1, sizeof(elem));
    for (i = 0; i < list[x].len; ++i)
        list[x].digit[i] += list[x - 2].digit[i];
    for (i = 0; list[x].digit[i] > 0; ++i) {
        list[x].digit[i + 1] += list[x].digit[i] / BASE;
        list[x].digit[i] %= BASE;
    }
    list[x].len = i;
}

void cal(int x)
{
    if (list[x - 1].len < 0) cal(x - 1);
    add(x);
}

int main(void)
{
    int i, n;

    memset(list[1].digit, 0, sizeof(long) * 102);
    memset(list[2].digit, 0, sizeof(long) * 102);
    memset(list[3].digit, 0, sizeof(long) * 102);
    list[1].len      = 1;
    list[1].digit[0] = 1;
    list[2].len      = 1;
    list[2].digit[0] = 1;
    list[3].len      = 1;
    list[3].digit[0] = 2;
    for (i = 4; list[i].len < 100; ++i)
        add(i);

    while (scanf("%d", &n) != EOF) {
        if (list[n].len < 0) cal(n);
        printf("%ld", list[n].digit[list[n].len - 1]);
        for (i = list[n].len - 2; i > -1; --i)
            printf("%010ld", list[n].digit[i]);
        printf("\n");
    }

    return 0;
}
