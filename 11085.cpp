#include <cstdio>
#include <cstring>

using namespace std;

bool v[8], sl[15], bsl[15];
struct parttern {
    int l[8];
} diction[1000];
int len;

void build(int *list, int x)
{
    int i;

    for (i = 0; i < 8; ++i)
        if (v[i] && sl[x + i] && bsl[7 - x + i]) {
            list[x] = i;
            if (x == 7) {
                memcpy(diction[len++].l, list, sizeof(int) * 8);
                return;
            }
            v[i]           = false;
            sl[x + i]      = false;
            bsl[7 - x + i] = false;
            build(list, x + 1);
            v[i]           = true;
            sl[x + i]      = true;
            bsl[7 - x + i] = true;
        }
}

int main(void)
{
    int index, i, j, list[8], min, cnt;

    memset(v, true, sizeof(v));
    memset(sl, true, sizeof(sl));
    memset(bsl, true, sizeof(bsl));

    len = 0;
    for (i = 0; i < 8; ++i) {
        v[i]       = false;
        sl[i]      = false;
        bsl[7 + i] = false;
        list[0]    = i;
        build(list, 1);
        v[i]       = true;
        sl[i]      = true;
        bsl[7 + i] = true;
    }

    index = 0;
    while (scanf("%d", list) != EOF) {
        list[0]--;
        for (i = 1; i < 8; ++i) {
            scanf("%d", list + i);
            list[i]--;
        }
        min = 9;

        for (i = 0; i < len; ++i) {
            cnt = 0;
            for (j = 0; j < 8 && cnt < min; ++j)
                cnt += list[j] != diction[i].l[j] ? 1 : 0;
            if (cnt < min) min = cnt;
        }

        printf("Case %d: %d\n", ++index, min);
    }

    return 0;
}
