#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

struct point {
    double x, y;
} list[101];

inline void swap(double *a, double *b)
{
    double tmpD;

    tmpD = *a;
    *a   = *b;
    *b   = tmpD;
}

double radius(point *A, point *B, point *C)
{
    double a, b, c, s, ab, ac, bc;

    ab = pow(A->x - B->x, 2) + pow(A->y - B->y, 2);
    ac = pow(A->x - C->x, 2) + pow(A->y - C->y, 2);
    bc = pow(B->x - C->x, 2) + pow(B->y - C->y, 2);

    if (ac > ab) swap(&ac, &ab);
    if (bc > ab) swap(&bc, &ab);

    if (ab >= ac + bc)
        return ab;
    else {
        a = sqrt(ab);
        b = sqrt(ac);
        c = sqrt(bc);
        s = (a + b + c) / 2;
        return pow(a * b * c / (2 * sqrt(s * (s - a) * (s - b) * (s - c))), 2);
    }
}

int main(void)
{
    int    n, i, j, k;
    double r, mr, tmpD;

    while (true) {
        scanf("%d", &n);
        if (!n) break;

        for (i = 0; i < n; ++i)
            scanf("%lf %lf", &list[i].x, &list[i].y);
        scanf("%lf", &r);
        r *= r * 4;

        if (n < 2)
            mr = 0;
        else if (n < 3)
            mr = pow(list[0].x - list[1].x, 2) + pow(list[0].y - list[1].y, 2);
        else {
            mr = 0;
            for (i = 0; i < n; ++i)
                for (j = i + 1; j < n; ++j)
                    for (k = j + 1; k < n; ++k) {
                        tmpD = radius(list + i, list + j, list + k);
                        if (tmpD > mr) mr = tmpD;
                    }
        }

        if (mr > r)
            printf("There is no way of packing that polygon.\n");
        else
            printf("The polygon can be packed in the circle.\n");
    }

    return 0;
}
