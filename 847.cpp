#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
    long cnt, p, n;

    while (scanf("%ld", &n) != EOF) {
        p   = 1;
        cnt = 0;
        while (p < n)
            p *= ++cnt % 2 ? 9 : 2;
        if (cnt % 2)
            printf("Stan wins.\n");
        else
            printf("Ollie wins.\n");
    }

    return 0;
}
