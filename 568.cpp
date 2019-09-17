#include <cstdio>

using namespace std;

int main(void)
{
    int n, tmpI, T[10001], F[10001], digit[10001], i, j;

    digit[0] = 1;
    T[0]     = 0;
    F[0]     = 0;
    digit[1] = 1;
    T[1]     = 0;
    F[1]     = 0;
    for (i = 2; i < 10001; ++i) {
        digit[i] = digit[i - 1];
        tmpI     = i;
        T[i]     = T[i - 1];
        F[i]     = F[i - 1];
        while (tmpI % 10 == 0)
            tmpI /= 10;
        while (tmpI % 2 == 0) {
            tmpI /= 2;
            T[i]++;
        }
        while (tmpI % 5 == 0) {
            tmpI /= 5;
            F[i]++;
        }
        if (T[i] > F[i]) {
            T[i] -= F[i];
            F[i] = 0;
        }
        else {
            F[i] -= T[i];
            T[i] = 0;
        }
        digit[i] *= (tmpI % 10);
        digit[i] %= 10;
    }

    for (i = 2; i < 10001; ++i) {
        if (T[i] > 0) {
            for (j = 0; j < T[i]; ++j) {
                digit[i] *= 2;
                digit[i] %= 10;
            }
        }
        else {
            for (j = 0; j < F[i]; ++j) {
                digit[i] *= 5;
                digit[i] %= 10;
            }
        }
    }

    while (scanf("%d", &n) != EOF)
        printf("%5d -> %d\n", n, digit[n]);

    return 0;
}
