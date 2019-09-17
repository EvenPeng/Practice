#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int  num, pos, num_tmp;
    char digits[1000001];

    while (1) {
        scanf("%s", digits);
        if (digits[0] == 'E') break;

        num = strlen(digits);

        if (num == 1 && digits[0] == '1') {
            printf("1\n");
            continue;
        }

        pos = 1;
        while (num > 1) {
            num_tmp = num;
            num     = 0;
            pos++;
            while (num_tmp > 0) {
                num++;
                num_tmp /= 10;
            }
        }

        printf("%d\n", pos + 1);
    }

    return 0;
}
