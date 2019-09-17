#include <cstdio>
#include <cstring>

using namespace std;

struct acc {
    int v, s;
} list[110][110];

int main(void)
{
    int n, k, ans;

    list[0][0].v = 1;
    list[0][0].s = 1;
    for (n = 1; n < 110; ++n) {
        list[0][n].v = 0;
        list[0][n].s = 1;
    }

    for (k = 1; k < 110; ++k) {
        list[k][0].v = 1;
        list[k][0].s = 1;
        for (n = 1; n < 110; ++n) {
            list[k][n].v = (list[k - 1][n].v + list[k][n - 1].v) % 1000000;
            list[k][n].s = (list[k][n].v + list[k][n - 1].s) % 1000000;
        }
    }

    while (true) {
        scanf("%d %d", &n, &k);
        if (!n && !k)
            break;
        else
            printf("%d\n", list[k - 1][n].s);
    }

    return 0;
}
