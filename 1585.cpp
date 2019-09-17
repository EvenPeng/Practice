#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char str[100];
    int  times, sum, cnt, i;

    scanf("%d", &times);
    while (times--) {
        scanf("%s", str);
        sum = 0;
        cnt = 1;

        for (i = 0; i < strlen(str); ++i)
            if (str[i] != 'O')
                cnt = 1;
            else {
                sum += cnt;
                cnt++;
            }

        printf("%d\n", sum);
    }

    return 0;
}
