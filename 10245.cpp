#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

struct point {
    double x, y, xy;
    bool   operator<(point other) const { return xy < other.xy; }
} list[10001];

int main(void)
{
    int    n, i, j;
    double min, dis;

    while (true) {
        scanf("%d", &n);
        if (!n) break;

        min = 9999.99996;
        for (i = 0; i < n; ++i) {
            scanf("%lf %lf", &list[i].x, &list[i].y);
            list[i].xy = sqrt(pow(list[i].x, 2) + pow(list[i].y, 2));
        }

        sort(list, list + n);

        for (i = 0; i < n; ++i)
            for (j = i + 1; j < n; ++j) {
                if (list[j].xy - list[i].xy >= min) break;
                dis = sqrt(pow(list[i].x - list[j].x, 2) + pow(list[i].y - list[j].y, 2));
                if (dis < min) min = dis;
            }

        if (min < 9999.99996)
            printf("%.4lf\n", min);
        else
            printf("INFINITY\n");
    }

    return 0;
}
