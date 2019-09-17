#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

static inline bool cmp(char *x, char *y, int len)
{
    int i;

    for (i = 0; i < len; ++i)
        if (x[i] != y[i]) return false;

    return true;
}

int main(void)
{
    bool flag;
    char str[1000005];
    int  len, i, j, max, seg;

    while (true) {
        scanf("%s", str);
        if (str[0] == '.')
            break;
        else
            len = strlen(str);

        flag = true;
        for (j = 1; j < len && flag; ++j)
            flag &= (str[0] == str[j]);
        if (flag)
            max = len;
        else {
            max = 1;
            for (i = 2; i <= (int)sqrt(len); ++i)
                if (len % i == 0) {
                    flag = true;
                    for (j = i; j < len && flag; j += i)
                        flag &= cmp(str, str + j, i);
                    if (flag) {
                        max = len / i;
                        break;
                    }
                    seg  = len / i;
                    flag = true;
                    for (j = seg; j < len && flag; j += seg)
                        flag &= cmp(str, str + j, seg);
                    if (flag) max = i;
                    ;
                }
        }

        printf("%d\n", max);
    }

    return 0;
}
