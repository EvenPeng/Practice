#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int    n, m, ln, lm, rn, rm, tn, tm;
    double f, tf;

    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 1 && m == 1) break;
        f  = (double)n / m;
        ln = rm = 0;
        lm = rn = tn = tm = 1;
        while (1) {
            tf = (double)tn / tm;
            if (tf < f) {
                ln = tn;
                lm = tm;
                printf("R");
            }else if (tf > f) {
                rn = tn;
                rm = tm;
                printf("L");
            }else{
                printf("\n");
                break;
            }
            tn = ln + rn;
            tm = lm + rm;
        }
    }

    return 0;
}
