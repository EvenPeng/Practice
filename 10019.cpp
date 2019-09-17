#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int  times, i, sum, b1, b2;
    int  cnt[10] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2};
    char arr[5];

    scanf("%d\n", &times);

    while (times-- > 0) {
        scanf("%s", arr);

        sum = 0;
        b2  = 0;
        for (i = 0; i < strlen(arr); ++i) {
            sum = (sum * 10) + (int)(arr[i] - '0');
            b2 += cnt[(int)(arr[i] - '0')];
        }

        b1 = 0;
        while (sum > 0) {
            b1 += sum & 1;
            sum = sum >> 1;
        }

        printf("%d %d\n", b1, b2);
    }

    return 0;
}
