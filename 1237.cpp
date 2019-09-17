#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct company {
    char name[30];
    int  l, h;
    bool operator<(company other) const { return l < other.l; }
} list[10002];

int main(void)
{
    int times, len, q, p, i, j, index, cnt;

    scanf("%d", &times);

    while (times--) {
        scanf("%d", &len);
        for (i = 0; i < len; ++i)
            scanf("%s %d %d", list[i].name, &list[i].l, &list[i].h);

        sort(list, list + len);

        scanf("%d", &q);
        for (i = 0; i < q; ++i) {
            scanf("%d", &p);

            cnt = 0;
            for (j = 0; j < len && list[j].l <= p; ++j)
                if (list[j].h >= p) {
                    index = j;
                    if (++cnt > 1) break;
                }

            if (cnt == 1)
                printf("%s\n", list[index].name);
            else
                printf("UNDETERMINED\n");
        }

        if (times) printf("\n");
    }

    return 0;
}
