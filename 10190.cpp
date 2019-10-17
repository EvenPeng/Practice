#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int n, m, vec[64], len;

    while (scanf("%d %d", &n, &m) != EOF) {
        if (n < 2 || m < 2)
            printf("Boring!\n");
        else {
            len    = 1;
            vec[0] = n;
            while (vec[len - 1] % m == 0) {
                vec[len] = vec[len - 1] / m;
                len++;
            }
            if (vec[len - 1] == 1) {
                printf("%d", vec[0]);
                for (int i = 1; i < len; ++i)
                    printf(" %d", vec[i]);
                printf("\n");
            }
            else {
                printf("Boring!\n");
            }
        }
    }

    return 0;
}
