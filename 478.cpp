#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

struct fig {
    char   type[2];
    double arr[6];
};

inline bool inR(fig *f, double x, double y)
{
    if (x <= f->arr[0] || x >= f->arr[2] || y <= f->arr[1] || y >= f->arr[3])
        return false;
    else
        return true;
}

inline bool inC(fig *f, double x, double y)
{
    if (pow(f->arr[0] - x, 2) + pow(f->arr[1] - y, 2) >= pow(f->arr[2], 2))
        return false;
    else
        return true;
}

inline bool inT(fig *f, double x, double y)
{
    double a = -((x * f->arr[3] - y * f->arr[2]) - (f->arr[0] * f->arr[3] - f->arr[1] * f->arr[2])) /
               (f->arr[2] * f->arr[5] - f->arr[3] * f->arr[4]);
    double b = ((x * f->arr[5] - y * f->arr[4]) - (f->arr[0] * f->arr[5] - f->arr[1] * f->arr[4])) /
               (f->arr[2] * f->arr[5] - f->arr[3] * f->arr[4]);
    if (a > 0 && b > 0 && a + b <= 1)
        return true;
    else
        return false;
}

int main(void)
{
    bool   flag;
    int    lenL, indexP, i;
    double x, y;
    fig    list[20];

    lenL = 0;
    while (true) {
        scanf("%s", list[lenL].type);
        if (list[lenL].type[0] == 'r') {
            scanf("%lf %lf %lf %lf", list[lenL].arr, list[lenL].arr + 1, list[lenL].arr + 2, list[lenL].arr + 3);
            if (list[lenL].arr[0] > list[lenL].arr[2]) {
                x                 = list[lenL].arr[0];
                list[lenL].arr[0] = list[lenL].arr[2];
                list[lenL].arr[2] = x;
            }
            if (list[lenL].arr[1] > list[lenL].arr[3]) {
                x                 = list[lenL].arr[1];
                list[lenL].arr[1] = list[lenL].arr[3];
                list[lenL].arr[3] = x;
            }
        }
        else if (list[lenL].type[0] == 'c')
            scanf("%lf %lf %lf", list[lenL].arr, list[lenL].arr + 1, list[lenL].arr + 2);
        else if (list[lenL].type[0] == 't') {
            scanf("%lf %lf %lf %lf %lf %lf", list[lenL].arr, list[lenL].arr + 1, list[lenL].arr + 2, list[lenL].arr + 3,
                  list[lenL].arr + 4, list[lenL].arr + 5);
            list[lenL].arr[2] -= list[lenL].arr[0];
            list[lenL].arr[3] -= list[lenL].arr[1];
            list[lenL].arr[4] -= list[lenL].arr[0];
            list[lenL].arr[5] -= list[lenL].arr[1];
        }
        else
            break;
        lenL++;
    }

    indexP = 1;
    while (true) {
        scanf("%lf %lf", &x, &y);
        if (x == 9999.9 && y == 9999.9) break;

        flag = true;
        for (i = 0; i < lenL; ++i) {
            if (list[i].type[0] == 'r') {
                if (inR(list + i, x, y)) {
                    printf("Point %d is contained in figure %d\n", indexP, i + 1);
                    flag = false;
                }
            }
            else if (list[i].type[0] == 'c') {
                if (inC(list + i, x, y)) {
                    printf("Point %d is contained in figure %d\n", indexP, i + 1);
                    flag = false;
                }
            }
            else if (list[i].type[0] == 't') {
                if (inT(list + i, x, y)) {
                    printf("Point %d is contained in figure %d\n", indexP, i + 1);
                    flag = false;
                }
            }
        }
        if (flag) printf("Point %d is not contained in any figure\n", indexP);
        indexP++;
    }

    return 0;
}
