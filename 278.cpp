#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char c[10];
    int  T, n, m, x, y;

    scanf("%d", &T);
    while (T--) {
        while (scanf("%s %d %d", c, &n, &m) != 3);
        n = n < m ? n : m;
        switch (c[0]) {
        case 'r':
        case 'Q':
            printf("%d\n", n);
            break;
        case 'k':
            if (n % 2 && m % 2) {
                x = ((n - 1) / 2 + n % 2) * ((m - 1) / 2 + m % 2);
                y = ((n - 1) / 2) * ((m - 1) / 2);
                printf("%d\n", x + y);
            }
            else
                printf("%d\n", (n * m) / 2);
            break;
        case 'K':
            n = (n - 1) / 2 + 1;
            m = (m - 1) / 2 + 1;
            printf("%d\n", n * m);
            break;
        }
    }

    return 0;
}

