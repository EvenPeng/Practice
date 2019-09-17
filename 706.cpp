#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

bool digit[10][7] = {
    {1, 1, 1, 0, 1, 1, 1}, {0, 0, 1, 0, 0, 1, 0}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 1, 1, 0, 1, 1}, {0, 1, 1, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 1}, {1, 1, 0, 1, 1, 1, 1}, {1, 0, 1, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 0, 1, 1},
};

int main(void)
{
    int  i, j, k, n;
    char arr[8];

    while (scanf("%d %s", &n, arr) != EOF && n > 0) {
        for (j = 0; j < strlen(arr); ++j) {
            printf(" ");
            k = n;
            if (digit[arr[j] - '0'][0])
                while (k-- > 0)
                    printf("-");
            else
                while (k-- > 0)
                    printf(" ");
            printf(" ");
            if (j < strlen(arr) - 1)
                printf(" ");
            else
                printf("\n");
        }
        for (i = 0; i < n; ++i) {
            for (j = 0; j < strlen(arr); ++j) {
                if (digit[arr[j] - '0'][1])
                    printf("|");
                else
                    printf(" ");
                k = n;
                while (k-- > 0)
                    printf(" ");
                if (digit[arr[j] - '0'][2])
                    printf("|");
                else
                    printf(" ");
                if (j < strlen(arr) - 1)
                    printf(" ");
                else
                    printf("\n");
            }
        }
        for (j = 0; j < strlen(arr); ++j) {
            printf(" ");
            k = n;
            if (digit[arr[j] - '0'][3])
                while (k-- > 0)
                    printf("-");
            else
                while (k-- > 0)
                    printf(" ");
            printf(" ");
            if (j < strlen(arr) - 1)
                printf(" ");
            else
                printf("\n");
        }
        for (i = 0; i < n; ++i) {
            for (j = 0; j < strlen(arr); ++j) {
                if (digit[arr[j] - '0'][4])
                    printf("|");
                else
                    printf(" ");
                k = n;
                while (k-- > 0)
                    printf(" ");
                if (digit[arr[j] - '0'][5])
                    printf("|");
                else
                    printf(" ");
                if (j < strlen(arr) - 1)
                    printf(" ");
                else
                    printf("\n");
            }
        }
        for (j = 0; j < strlen(arr); ++j) {
            printf(" ");
            k = n;
            if (digit[arr[j] - '0'][6])
                while (k-- > 0)
                    printf("-");
            else
                while (k-- > 0)
                    printf(" ");
            printf(" ");
            if (j < strlen(arr) - 1)
                printf(" ");
            else
                printf("\n");
        }
        printf("\n");
    }

    return 0;
}
