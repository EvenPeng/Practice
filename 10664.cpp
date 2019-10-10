#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char c;
    int  T, len, arr[20], lenc, comb[200], sum, x;
    bool exist[201];

    scanf("%d\n", &T);
    while (T--) {
        len = 0;
        sum = 0;
        memset(exist, false, sizeof(exist));
        while (1) {
            scanf("%d%c", arr + len, &c);
            sum += arr[len++];
            if (c == '\n') break;
        }
        if (sum % 2)
            printf("NO\n");
        else {
            sort(arr, arr + len);
            sum /= 2;
            lenc           = 1;
            comb[0]        = arr[len - 1];
            exist[comb[0]] = true;

            for (int i = len - 2; i > -1; i--)
                for (int j = lenc - 1; j > -1; j--) {
                    x = arr[i] + comb[j];
                    if (x <= sum && !exist[x]) {
                        comb[lenc++] = x;
                        exist[x]     = true;
                        if (x == sum) {
                            i = -1;
                            j = -1;
                        }
                    }
                }

            if (comb[lenc - 1] == sum)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
