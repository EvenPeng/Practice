#include <cstdio>
#include <cstring>

using namespace std;

struct object {
    int w, v;
};

void sortO(object *list, int len)
{
    int    i     = 0;
    int    j     = len - 1;
    int    pivot = list[len / 2].w;
    object tmpS;

    if (len < 2) return;

    while (true) {
        while (list[i].w - pivot < 0)
            ++i;
        while (list[j].w - pivot > 0)
            --j;
        if (i >= j) break;

        memcpy(&tmpS, list + i, sizeof(object));
        memcpy(list + i, list + j, sizeof(object));
        memcpy(list + j, &tmpS, sizeof(object));
        i++;
        j--;
    }

    sortO(list, i);
    sortO(list + i, len - i);
}

int main(void)
{
    object objs[1001];
    int    times, i, j, p, lenO, lenP, people[101], dp[32], sum, max;

    scanf("%d", &times);
    while (times-- > 0) {
        scanf("%d", &lenO);
        for (i = 0; i < lenO; ++i)
            scanf("%d %d", &objs[i].v, &objs[i].w);
        scanf("%d", &lenP);
        max = 0;
        for (i = 0; i < lenP; ++i) {
            scanf("%d", &people[i]);
            if (max < people[i]) max = people[i];
        }

        sortO(objs, lenO);

        memset(dp, 0, sizeof(int) * (max + 1));
        for (i = 0; i < lenO; ++i)
            for (j = max; j - objs[i].w > -1; --j)
                if (dp[j] < objs[i].v + dp[j - objs[i].w]) dp[j] = objs[i].v + dp[j - objs[i].w];

        sum = 0;
        for (i = 0; i < lenP; ++i)
            sum += dp[people[i]];
        printf("%d\n", sum);
    }

    return 0;
}
