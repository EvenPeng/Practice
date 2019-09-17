#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int  i, j, times, n;
    char in[10010], out[10010];

    scanf("%d\n", &times);
    while (times--) {
        gets(in);
        n = (int)sqrt(strlen(in));
        if (n * n != strlen(in))
            printf("INVALID\n");
        else {
            for (i = 0; i < n; ++i)
                for (j = 0; j < n; ++j)
                    out[i * n + j] = in[j * n + i];
            out[n * n] = '\0';
            printf("%s\n", out);
        }
    }

    return 0;
}
