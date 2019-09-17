#include <cstdio>

using namespace std;

int main(void)
{
    int  n, sum, len;
    char arr[32];

    while (scanf("%d", &n) != EOF && n > 0) {
        sum = 0;
        printf("The parity of ");
        len = 0;
        while (n > 0) {
            if (n & 1) {
                arr[len] = '1';
                sum++;
            }
            else
                arr[len] = '0';
            len++;
            n = n >> 1;
        }
        while (--len > -1)
            printf("%c", arr[len]);
        printf(" is %d (mod 2).\n", sum);
    }

    return 0;
}
