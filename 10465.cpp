#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int GCD(int x, int y)
{
    int z;

    while (1) {
        z = x;
        y %= x;
        if (!y) break;
        z = y;
        x %= y;
        if (!x) break;
    }

    return z;
}

int LCM(int x, int y) { return x * y / GCD(x, y); }

int main(void)
{
    int m, n, t, sum;
    int x, y, z, d, lcm, my, re;

    while (scanf("%d %d %d", &m, &n, &t) != EOF) {
        if (m > n) swap(n, m);
        lcm = LCM(m, n);
        sum = t / lcm;
        t %= lcm;

        if (sum) {
            sum--;
            t += lcm;
        }
        sum *= lcm / m;

        x = t / m;
        y = 0;
        z = t % m;
        if (z) {
            my = 0;
            re = z;
            while (z && x) {
                x--;
                z += m;
                if (z >= n) {
                    y++;
                    z -= n;
                }
                if (z < re) {
                    my = y;
                    re = z;
                }
            }
        }

        if (z) {
            y = my;
            x = (t - n * y) / m;
            z = t - x * m - y * n;
        }

        sum += x + y;
        if (!z)
            printf("%d\n", sum);
        else
            printf("%d %d\n", sum, z);
    }

    return 0;
}
