#include <cmath>
#include <cstdio>

using namespace std;

void sortP(double *peak, int len)
{
    int    i = 0;
    int    j = len - 1;
    double tmpI, pivot = peak[(len / 2) * 2];

    if (len < 2) return;

    while (true) {
        while (peak[i * 2] < pivot)
            ++i;
        while (peak[j * 2] > pivot)
            --j;
        if (i >= j) break;

        tmpI            = peak[i * 2];
        peak[i * 2]     = peak[j * 2];
        peak[j * 2]     = tmpI;
        tmpI            = peak[i * 2 + 1];
        peak[i * 2 + 1] = peak[j * 2 + 1];
        peak[j * 2 + 1] = tmpI;
        i++;
        j--;
    }

    sortP(peak, i);
    sortP(peak + i * 2, len - i);
}

int main(void)
{
    int    times, len, i;
    double sum, height, peak[202], x, y;

    scanf("%d", &times);

    while (times-- > 0) {
        scanf("%d", &len);
        for (i = 0; i < len; ++i)
            scanf("%lf %lf", &peak[i * 2], &peak[i * 2 + 1]);

        sortP(peak, len);

        sum    = 0;
        height = 0;
        for (i = len - 1; i > -1; --i)
            if (peak[i * 2 + 1] > height) {
                y      = peak[i * 2 + 1] - height;
                x      = (peak[i * 2] - peak[i * 2 + 2]) * y / (peak[i * 2 + 1] - peak[i * 2 + 3]);
                height = peak[i * 2 + 1];
                sum += sqrt(pow(x, 2) + pow(y, 2));
            }

        printf("%.2lf\n", sum);
    }

    return 0;
}
