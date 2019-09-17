#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char str[10], d[50];
    ;
    int i, b1, b2, num, convert[128];

    for (i = 0; i < 10; ++i) {
        d[i]             = '0' + i;
        convert['0' + i] = i;
    }
    for (i = 0; i < 26; ++i) {
        d[10 + i]        = 'A' + i;
        convert['A' + i] = 10 + i;
        convert['a' + i] = 10 + i;
    }

    while (scanf("%s %d %d", str, &b1, &b2) != EOF) {
        num = 0;
        for (i = 0; i < strlen(str); ++i)
            num = num * b1 + convert[str[i]];
        if (b1 > b2 && num > pow(b2, 7) - 1) {
            printf("  ERROR\n");
            continue;
        }
        if (num > 0) {
            str[7] = '\0';
            for (i = 6; num > 0; --i) {
                str[i] = d[num % b2];
                num /= b2;
            }
            while (i > -1)
                str[i--] = ' ';
            printf("%s\n", str);
        }
        else
            printf("      0\n");
    }

    return 0;
}
