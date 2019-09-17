#include <cstdio>
#include <cstring>

using namespace std;

int list[151];

void gen(int x)
{
    int step, i, n, curr;

    step = 2;
    while (true) {
        n    = x;
        curr = x - 1;
        while (n > 1) {
            curr += step;
            curr -= curr < n ? 1 : n;
            n--;
            curr %= n;
            if (curr == 0) break;
        }

        if (n == 1)
            break;
        else
            step++;
    }

    list[x] = step;
}

int main(void)
{
    int n;

    memset(list, -1, sizeof(int) * 151);

    while (true) {
        scanf("%d", &n);
        if (n < 1) break;
        if (list[n] < 1) gen(n);
        printf("%d\n", list[n]);
    }

    return 0;
}
