#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    unsigned int n, i, j, a, b;

    while (true) {
        scanf("%d", &n);
        if (!n) break;
        a = 0;
        b = 0;
        i = 1;
        j = 0;
        while (i <= n) {
            if (n & i) {
                if (j % 2)
                    b += i;
                else
                    a += i;
                j++;
            }
            i = i << 1;
        }
        printf("%d %d\n", a, b);
    }

    return 0;
}
