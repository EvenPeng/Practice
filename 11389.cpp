#include<algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int n, d, r, md;
    int mr[100], er[100];

    while (1) {
        scanf("%d %d %d", &n, &d, &r);
        if (!n && !d && !r) break;

        for (int i = 0; i < n; ++i)
            scanf("%d", mr + i);
        for (int i = 0; i < n; ++i)
            scanf("%d", er + i);

        sort(mr, mr + n);
        sort(er, er + n);

        md = 0;
        for (int i = 0, j = n - 1; i < n; ++i, --j)
            if (mr[i] + er[j] > d) md += mr[i] + er[j] - d;

        printf("%d\n", md * r);
    }

    return 0;
}
