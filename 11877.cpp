#include <cstdio>

using namespace std;

int main(void)
{
    int sum, left, get, n;

    while (true) {
        scanf("%d", &n);
        if (n < 1) break;
        left = n;
        sum  = 0;
        while (left > 2) {
            get = left / 3;
            sum += get;
            left = get + left % 3;
        }
        if (left == 2)
            printf("%d\n", sum + 1);
        else
            printf("%d\n", sum);
    }

    return 0;
}
