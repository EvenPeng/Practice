#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int  times, index, n;
    long list[51];

    list[1] = 2;
    list[2] = 3;
    for (n = 3; n < 51; ++n)
        list[n] = list[n - 1] + list[n - 2];

    scanf("%d", &times);
    index = 0;
    while (times--) {
        scanf("%d", &n);
        printf("Scenario #%d:\n%ld\n\n", ++index, list[n]);
    }

    return 0;
}
