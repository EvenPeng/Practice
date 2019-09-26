#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int T, D, I;
    int power[20];

    power[1] = 2;
    for (int i = 2; i < 20; ++i)
        power[i] = power[i - 1] << 1;

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &D, &I);
        int v = (I - 1) % power[D - 1], w = 0;
        for (int i = 1; i < D; ++i) {
            w <<= 1;
            w += v & 1;
            v >>= 1;
        }
        printf("%d\n", power[D - 1] + w);
    }

    return 0;
}
