#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int  tmp, len;
    bool flag, leap, hul, bul;
    char num[1000000];

    while (scanf("%s", num) != EOF) {
        if (flag)
            printf("\n");
        else
            flag = true;

        len = strlen(num);

        for (int i = 0; i < len; ++i)
            num[i] -= 48;

        tmp = (int)num[0];
        for (int i = 1; i < len; ++i)
            tmp = (tmp * 10 + (int)num[i]) % 4;
        leap = (tmp % 4 == 0);

        tmp = (int)num[0];
        for (int i = 1; i < len; ++i)
            tmp = (tmp * 10 + (int)num[i]) % 100;

        leap &= (tmp != 0);

        if (!leap) {
            tmp = (int)num[0];
            for (int i = 1; i < len; ++i)
                tmp = (tmp * 10 + (int)num[i]) % 400;

            leap = (tmp == 0);
        }

        tmp = (int)num[0];
        for (int i = 1; i < len; ++i)
            tmp = (tmp * 10 + (int)num[i]) % 15;
        hul = (tmp % 15 == 0);

        if (leap) {
            printf("This is leap year.\n");
            if (hul) printf("This is huluculu festival year.\n");

            tmp = (int)num[0];
            for (int i = 1; i < len; ++i)
                tmp = (tmp * 10 + (int)num[i]) % 55;
            bul = (tmp % 55 == 0);

            if (bul) printf("This is bulukulu festival year.\n");
        }
        else if (hul)
            printf("This is huluculu festival year.\n");
        else
            printf("This is an ordinary year.\n");
    }

    return 0;
}
