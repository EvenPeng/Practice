#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char arr[10000], list[85000][6];
    int  len, i, j, k, l, m, lenL, sum, diff, map[130];

    lenL = 0;
    for (i = 0; i < 26; ++i) {
        list[lenL][0]   = 'a' + i;
        list[lenL++][1] = '\0';
    }

    for (i = 0; i < 26; ++i)
        for (j = i + 1; j < 26; ++j) {
            list[lenL][0]   = 'a' + i;
            list[lenL][1]   = 'a' + j;
            list[lenL++][2] = '\0';
        }

    for (i = 0; i < 26; ++i)
        for (j = i + 1; j < 26; ++j)
            for (k = j + 1; k < 26; ++k) {
                list[lenL][0]   = 'a' + i;
                list[lenL][1]   = 'a' + j;
                list[lenL][2]   = 'a' + k;
                list[lenL++][3] = '\0';
            }

    for (i = 0; i < 26; ++i)
        for (j = i + 1; j < 26; ++j)
            for (k = j + 1; k < 26; ++k)
                for (l = k + 1; l < 26; ++l) {
                    list[lenL][0]   = 'a' + i;
                    list[lenL][1]   = 'a' + j;
                    list[lenL][2]   = 'a' + k;
                    list[lenL][3]   = 'a' + l;
                    list[lenL++][4] = '\0';
                }

    for (i = 0; i < 26; ++i)
        for (j = i + 1; j < 26; ++j)
            for (k = j + 1; k < 26; ++k)
                for (l = k + 1; l < 26; ++l)
                    for (m = l + 1; m < 26; ++m) {
                        list[lenL][0]   = 'a' + i;
                        list[lenL][1]   = 'a' + j;
                        list[lenL][2]   = 'a' + k;
                        list[lenL][3]   = 'a' + l;
                        list[lenL][4]   = 'a' + m;
                        list[lenL++][5] = '\0';
                    }

    while (scanf("%s", arr) != EOF) {
        len = strlen(arr);
        if (len > 5) {
            printf("0\n");
            continue;
        }
        sum = -1;
        for (i = 1; i < len; ++i) {
            if (arr[i] <= arr[i - 1]) {
                sum = 0;
                break;
            }
        }
        if (sum != 0) {
            i = -1;
            j = lenL;
            while (j - i > 1) {
                sum = (i + j) / 2;
                if (len < strlen(list[sum]) || (len == strlen(list[sum]) && strcmp(arr, list[sum]) < 0))
                    j = sum;
                else if (len > strlen(list[sum]) || (len == strlen(list[sum]) && strcmp(arr, list[sum])) > 0)
                    i = sum;
                else
                    break;
            }
            printf("%d\n", sum + 1);
        }
        else
            printf("0\n");
    }

    return 0;
}
