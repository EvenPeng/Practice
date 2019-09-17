#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int times, index, bm, bd, by, em, ed, ey, sum;

    scanf("%d", &times);
    index = 0;

    while (times--) {
        scanf("%d/%d/%d", &bd, &bm, &by);
        scanf("%d/%d/%d", &ed, &em, &ey);
        if (by >= ey) {
            sum = by - ey;
            if (bm < em || (bm == em && bd < ed)) sum--;
        }
        else
            sum = -1;

        if (sum < 0)
            printf("Case #%d: Invalid birth date\n", ++index);
        else if (sum > 130)
            printf("Case #%d: Check birth date\n", ++index);
        else
            printf("Case #%d: %d\n", ++index, sum);
    }

    return 0;
}
