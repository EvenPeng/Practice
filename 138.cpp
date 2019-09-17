#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
    int x, y, diff, i;

    x    = 6;
    y    = 8;
    diff = 0;
    i    = 0;

    while (i < 10) {
        if (diff < 0) {
            diff += 2 * x + 1;
            x++;
        }
        else if (diff > 0) {
            y++;
            diff -= y;
        }
        else {
            printf("%10d%10d\n", x, y);
            i++;
            diff += 2 * x + 1;
            x++;
        }
    }

    return 0;
}
