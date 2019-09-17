#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    unsigned int n, l, u, m, i, curr;

    while (scanf("%u %u %u", &n, &l, &u) != EOF) {
        m = 0;

        i = 1 << 31;
        while (i > u)
            i >>= 1;

        while (i > 0) {
            curr = i + m;
            if (i & n)
                m += curr > l ? 0 : i;
            else
                m += curr > u ? 0 : i;
            i >>= 1;
        }

        printf("%u\n", m);
    }

    return 0;
}
