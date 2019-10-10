#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int x1, x2, y1, y2, dx, dy;

    while (1) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (!x1 && !x2 && !y1 && !y2) break;

        dx = abs(x1 - x2);
        dy = abs(y1 - y2);

        if (!dx && !dy)
            printf("0\n");
        else if (!dx || !dy || dx == dy)
            printf("1\n");
        else
            printf("2\n");
    }

    return 0;
}
