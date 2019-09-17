#include <cstdio>
#include <cstring>

using namespace std;

struct element {
    int v, n, sn;
} list[20];

bool exist, first;
int  goal, len;

void show()
{
    int i, j;

    first = true;
    for (i = 0; i < len; ++i) {
        for (j = 0; j < list[i].sn; ++j)
            if (!first)
                printf("+%d", list[i].v);
            else {
                printf("%d", list[i].v);
                first = false;
            }
    }

    printf("\n");
}

void match(int index, int sum)
{
    int i;

    if (sum == goal) {
        show();
        exist = true;
        return;
    }
    else if (index == len)
        return;

    for (i = list[index].n; i > -1; --i) {
        list[index].sn = i;
        match(index + 1, sum + i * list[index].v);
    }
}

int main(void)
{
    int i;

    while (true) {
        scanf("%d %d", &goal, &i);
        if (!goal && !i) break;

        len = 0;
        while (i--) {
            scanf("%d", &list[len].v);
            if (len == 0 || list[len].v != list[len - 1].v) {
                list[len].n  = 1;
                list[len].sn = 0;
                len++;
            }
            else
                list[len - 1].n++;
        }

        exist = false;
        printf("Sums of %d:\n", goal);
        match(0, 0);
        if (!exist) printf("NONE\n");
    }

    return 0;
}
