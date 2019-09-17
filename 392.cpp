#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    bool first;
    int  i, num;

    while (scanf("%d", &num) != EOF) {
        first = true;
        for (i = 8; i > 1; --i) {
            if (num != 0) {
                if (first) {
                    if (num == 1)
                        printf("x^%d", i);
                    else if (num == -1)
                        printf("-x^%d", i);
                    else
                        printf("%dx^%d", num, i);
                    first = false;
                }
                else {
                    if (num > 0)
                        printf(" + ");
                    else {
                        num *= -1;
                        printf(" - ");
                    }
                    if (num == 1)
                        printf("x^%d", i);
                    else
                        printf("%dx^%d", num, i);
                }
            }
            scanf("%d", &num);
        }
        if (num != 0) {
            if (first) {
                if (num == 1)
                    printf("x");
                else if (num == -1)
                    printf("-x");
                else
                    printf("%dx", num);
                first = false;
            }
            else {
                if (num > 0)
                    printf(" + ");
                else {
                    num *= -1;
                    printf(" - ");
                }
                if (num == 1)
                    printf("x");
                else
                    printf("%dx", num);
            }
        }
        scanf("%d", &num);
        if (num != 0) {
            if (first) {
                printf("%d", num);
                first = false;
            }
            else {
                if (num > 0)
                    printf(" + ");
                else {
                    num *= -1;
                    printf(" - ");
                }
                printf("%d", num);
            }
        }
        if (first)
            printf("0\n");
        else
            printf("\n");
    }

    return 0;
}
