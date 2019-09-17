#include <cstdio>

using namespace std;

int main(void)
{
    bool flag;
    int  tmpI, i, len, list[100000], cnt[100000];

    len = 0;

    while (scanf("%d", &tmpI) != EOF) {
        flag = true;
        for (i = 0; i < len; ++i)
            if (list[i] == tmpI) {
                cnt[i]++;
                flag = false;
            }

        if (flag) {
            list[len]  = tmpI;
            cnt[len++] = 1;
        }
    }

    for (i = 0; i < len; ++i)
        printf("%d %d\n", list[i], cnt[i]);

    return 0;
}
