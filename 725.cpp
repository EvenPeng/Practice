#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct elem {
    int  x, y, v;
    bool operator<(elem other) const { return v == other.v ? x < other.x : v < other.v; }
} list[1000];

bool check[10];
int  v[10][5], len;

void exploreX(int, int, int);

void exploreY(int index, int x, int y)
{
    int i;

    for (i = 0; i < 10; ++i)
        if (check[i]) {
            check[i] = false;
            exploreX(index + 1, x, y + v[i][index]);
            check[i] = true;
        }
}

void exploreX(int index, int x, int y)
{
    int i;

    if (index == 5) {
        if (x % y == 0) {
            list[len].x   = x;
            list[len].y   = y;
            list[len++].v = x / y;
        }
        return;
    }

    for (i = 0; i < 10; ++i)
        if (check[i]) {
            check[i] = false;
            exploreY(index, x + v[i][index], y);
            check[i] = true;
        }
}

int main(void)
{
    bool first;
    int  n, i, j, head[80], seg[80];

    memset(seg, 0, sizeof(seg));

    for (i = 0; i < 10; ++i) {
        check[i] = true;
        v[i][0]  = i * 10000;
        for (j = 1; j < 5; ++j)
            v[i][j] = v[i][j - 1] / 10;
    }

    len = 0;
    for (i = 0; i < 10; ++i) {
        check[i] = false;
        for (j = 0; j <= i / 2; ++j)
            if (check[j]) {
                check[j] = false;
                exploreX(1, v[i][0], v[j][0]);
                check[j] = true;
            }
        check[i] = true;
    }
    sort(list, list + len);

    head[list[0].v] = 0;
    seg[list[0].v]  = 1;
    for (i = 1; i < len; ++i) {
        if (list[i].v == list[i - 1].v)
            seg[list[i].v]++;
        else {
            head[list[i].v] = i;
            seg[list[i].v]  = 1;
        }
    }

    first = true;
    while (true) {
        scanf("%d", &n);
        if (!n) break;
        if (!first)
            printf("\n");
        else
            first = false;

        if (n < 2 || 79 < n || seg[n] == 0)
            printf("There are no solutions for %d.\n", n);
        else
            for (i = 0; i < seg[n]; ++i)
                printf("%05d / %05d = %d\n", list[head[n] + i].x, list[head[n] + i].y, n);
    }

    return 0;
}
