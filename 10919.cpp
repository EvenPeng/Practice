#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int  k, m, r, c, tmp, index, meet;
    bool flag, course[10000];

    while (1) {
        scanf("%d", &k);
        if (k < 1) break;

        scanf("%d", &m);

        for (int i = 0; i < 10000; ++i)
            course[i] = false;

        for (int i = 0; i < k; ++i) {
            scanf("%d", &tmp);
            course[tmp] = true;
        }

        flag = true;

        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &c, &r);

            meet = 0;

            for (int j = 0; j < c; ++j) {
                scanf("%d", &tmp);
                if (!flag || meet == r) continue;
                if (course[tmp]) meet++;
            }

            if (meet != r) flag = false;
        }

        if (flag)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
