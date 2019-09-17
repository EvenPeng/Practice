#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int times, a, b, pay;

    scanf("%d", &times);

    while (times--) {
        scanf("%d %d %d", &a, &b, &pay);
        printf("%d\n", (2 * a - b) * pay / (a + b));
    }

    return 0;
}
