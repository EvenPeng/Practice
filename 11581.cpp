#include <cstdio>
#include <cstring>

using namespace std;

int next(int *a)
{
    int b = *a;

    *a = 0;
    if (b & 1) {
        *a ^= 1 << 1;
        *a ^= 1 << 3;
    }
    if (b & 2) {
        *a ^= 1 << 0;
        *a ^= 1 << 2;
        *a ^= 1 << 4;
    }
    if (b & 4) {
        *a ^= 1 << 1;
        *a ^= 1 << 5;
    }
    if (b & 8) {
        *a ^= 1 << 0;
        *a ^= 1 << 4;
        *a ^= 1 << 6;
    }
    if (b & 16) {
        *a ^= 1 << 1;
        *a ^= 1 << 3;
        *a ^= 1 << 5;
        *a ^= 1 << 7;
    }
    if (b & 32) {
        *a ^= 1 << 2;
        *a ^= 1 << 4;
        *a ^= 1 << 8;
    }
    if (b & 64) {
        *a ^= 1 << 3;
        *a ^= 1 << 7;
    }
    if (b & 128) {
        *a ^= 1 << 4;
        *a ^= 1 << 6;
        *a ^= 1 << 8;
    }
    if (b & 256) {
        *a ^= 1 << 5;
        *a ^= 1 << 7;
    }

    return *a;
}

int main(void)
{
    int times, curr, i, b, l;

    scanf("%d", &times);

    while (times--) {
        curr = 0;

        for (i = 0; i < 9; ++i) {
            scanf("%1d", &b);
            curr += (b << i);
        }

        if (!curr)
            printf("-1\n");
        else {
            l = 0;
            while (next(&curr))
                ++l;
            printf("%d\n", l);
        }
    }

    return 0;
}
