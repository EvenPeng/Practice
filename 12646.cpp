#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int a, b, c, sum;

    while (scanf("%d %d %d", &a, &b, &c) != EOF) {
        sum = a * 4 + b * 2 + c;
        switch (sum) {
        case 4:
        case 3:
            printf("A\n");
            break;
        case 5:
        case 2:
            printf("B\n");
            break;
        case 6:
        case 1:
            printf("C\n");
            break;
        default:
            printf("*\n");
        }
    }

    return 0;
}
