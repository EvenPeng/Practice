#include <cstdio>
#include <cstring>

using namespace std;

char exp[10001], c;
int  size[128][2], stack[1000][2], lenS, sum;

int main(void)
{
    bool err;
    char x, y;
    int  i, n;

    scanf("%d\n", &n);

    for (i = 0; i < n; ++i) {
        scanf("%c", &c);
        scanf("%d %d\n", &size[c][0], &size[c][1]);
    }

    while (scanf("%s\n", exp) != EOF) {
        lenS = 0;
        sum  = 0;
        err  = false;
        if (strlen(exp) < 2)
            printf("0\n");
        else {
            for (i = 0; i < strlen(exp); ++i) {
                if (exp[i] == '(')
                    continue;
                else if (exp[i] == ')') {
                    if (lenS < 2 || stack[lenS - 1][0] != stack[lenS - 2][1]) {
                        err = true;
                        break;
                    }
                    else {
                        sum += stack[lenS - 2][0] * stack[lenS - 1][0] * stack[lenS - 1][1];
                        stack[lenS - 2][1] = stack[lenS - 1][1];
                        lenS--;
                    }
                }
                else {
                    stack[lenS][0] = size[exp[i]][0];
                    stack[lenS][1] = size[exp[i]][1];
                    lenS++;
                }
            }
            if (err)
                printf("error\n");
            else
                printf("%d\n", sum);
        }
    }

    return 0;
}
