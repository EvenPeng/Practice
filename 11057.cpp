#include <algorithm>
#include <cstdio>

using namespace std;

int list[10001], len, sum;

bool bs(int i, int x)
{
    int j = len;
    int m = (i + j) / 2;

    while (j - i > 1) {
        m = (i + j) / 2;
        if (x < list[m])
            j = m;
        else if (x > list[m])
            i = m;
        else
            return true;
    }

    return false;
}

int main(void)
{
    int i, fit;

    while (scanf("%d", &len) != EOF) {
        for (i = 0; i < len; ++i)
            scanf("%d", list + i);
        scanf("%d", &sum);
        sort(list, list + len);

        for (i = 0; list[i] <= sum - list[i]; ++i)
            if (bs(i, sum - list[i])) fit = list[i];

        printf("Peter should buy books whose prices are %d and %d.\n\n", fit, sum - fit);
    }

    return 0;
}
