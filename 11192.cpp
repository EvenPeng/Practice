#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char str[105];
    int  i, j, n, len;

    while (true) {
        scanf("%d", &n);
        if (n < 1) break;
        scanf("%s", str);
        i   = 0;
        len = strlen(str);
        n   = len / n;
        while (i < len) {
            j = i + n < len ? i + n : len;
            while (--j >= i)
                printf("%c", str[j]);
            i += n;
        }
        printf("\n");
    }

    return 0;
}
