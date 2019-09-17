#include <cmath>
#include <cstdio>

using namespace std;

struct figure {
    char   type[2];
    double x1, x2, y1, y2;
};

int main(void)
{
    bool   flag;
    int    len, i, index;
    figure list[10];
    double x, y;

    len = 0;
    while (true) {
        scanf("%s", list[len].type);
        if (list[len].type[0] == 'r')
            scanf("%lf %lf %lf %lf", &list[len].x1, &list[len].y2, &list[len].x2, &list[len].y1);
        else if (list[len].type[0] == 'c')
            scanf("%lf %lf %lf", &list[len].x1, &list[len].y1, &list[len].x2);
        else
            break;
        len++;
    }

    index = 0;
    while (true) {
        scanf("%lf %lf", &x, &y);
        if (x == 9999.9 && y == 9999.9) break;
        flag = true;
        index++;
        for (i = 0; i < len; ++i)
            if ((list[i].type[0] == 'r' && list[i].x1 <= x && x <= list[i].x2 && list[i].y1 <= y && y <= list[i].y2) ||
                (list[i].type[0] == 'c' && (pow(x - list[i].x1, 2) + pow(y - list[i].y1, 2) <= pow(list[i].x2, 2)))) {
                printf("Point %d is contained in figure %d\n", index, i + 1);
                flag = false;
            }

        if (flag) printf("Point %d is not contained in any figure\n", index);
    }

    return 0;
}
