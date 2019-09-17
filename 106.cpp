#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int T[1000001], P[1000001], sumP;

inline bool relativePrime(int x, int y)
{
    while ((x %= y) && (y %= x))
        ;
    return x == 1 || y == 1;
}

int main(void)
{
    int n, bound, i, j, k, x, y, z, X, Y, Z, sq[1005];

    for (i = 0; i < 1005; ++i)
        sq[i] = i * i;

    memset(T, 0, sizeof(int) * 1000001);
    for (i = 0; i < 1000001; ++i)
        P[i] = 1000001;

    for (i = 1; i < 1001; ++i)
        for (j = i + 1;; j += 2)
            if (i % 3 == 0 && j % 3 == 0)
                continue;
            else if (relativePrime(i, j)) {
                x = 2 * j * i;
                y = sq[j] - sq[i];
                z = sq[j] + sq[i];
                if (z > 1000001) break;
                T[z]++;
                for (X = x, Y = y, Z = z; Z < 1000001; X += x, Y += y, Z += z) {
                    P[X] = Z < P[X] ? Z : P[X];
                    P[Y] = Z < P[Y] ? Z : P[Y];
                    P[Z] = Z;
                }
            }

    for (i = 1; i < 1000001; ++i)
        T[i] += T[i - 1];

    while (scanf("%d", &n) != EOF) {
        sumP = n;
        for (i = 1; i <= n; ++i)
            if (P[i] <= n) sumP--;
        printf("%d %d\n", T[n], sumP);
    }

    return 0;
}
