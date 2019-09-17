#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
    int n, i, list[1001], avg, psum, nsum, h;

    while (scanf("%d", &n) != EOF) {
        if (n < 1) break;
        avg = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d.%d", &h, &list[i]);
            list[i] += h * 100;
            avg += list[i];
        }
        avg  = (int)(1.0 * avg / n + 0.5);
        psum = 0;
        nsum = 0;
        for (i = 0; i < n; ++i) {
            if (list[i] > avg)
                psum += list[i] - avg;
            else if (list[i] < avg)
                nsum += avg - list[i];
        }
        if (psum < nsum)
            printf("$%d.%02d\n", psum / 100, psum % 100);
        else
            printf("$%d.%02d\n", nsum / 100, nsum % 100);
    }

    return 0;
}
