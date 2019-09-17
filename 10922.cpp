#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char list[1010], map[128];
    int  i, len, sum, tmpI, degree;

    for (i = 0; i < 10; ++i)
        map[i + '0'] = i;

    while (true) {
        scanf("%s", list);
        if (list[0] == '0') break;

        len = strlen(list);
        sum = 0;
        for (i = 0; i < len; ++i)
            sum += map[list[i]];

        printf("%s is ", list);
        if (sum % 9)
            printf("not a multiple of 9.\n");
        else {
            degree = 1;
            while (sum > 9) {
                tmpI = sum;
                sum  = 0;
                while (tmpI > 0) {
                    sum += tmpI % 10;
                    tmpI /= 10;
                }
                degree++;
            }
            printf("a multiple of 9 and has 9-degree %d.\n", degree);
        }
    }

    return 0;
}
