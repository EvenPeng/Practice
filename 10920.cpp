#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    unsigned long s, p, r, c, seg, diff;

    while (true) {
        scanf("%lu %lu", &s, &p);
        if (!s && !p) break;

        seg = (unsigned long)sqrt(p);
        seg -= seg % 2 ? 0 : 1;
        r = c = (s + 1) / 2 + seg / 2;
        diff  = p - seg * seg;
        if (diff) {
            r++;
            diff--;
        }
        if (diff) {
            c -= diff > seg ? seg : diff;
            diff -= diff > seg ? seg : diff;
        }
        seg++;
        if (diff) {
            r -= diff > seg ? seg : diff;
            diff -= diff > seg ? seg : diff;
        }
        if (diff) {
            c += diff > seg ? seg : diff;
            diff -= diff > seg ? seg : diff;
        }
        seg++;
        if (diff) {
            r += diff > seg ? seg : diff;
            diff -= diff > seg ? seg : diff;
        }

        printf("Line = %lu, column = %lu.\n", r, c);
    }

    return 0;
}
