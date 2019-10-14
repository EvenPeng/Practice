#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main(void)
{
    int                      n, x, y, match;
    map<int, map<int, bool>> check;

    while (1) {
        scanf("%d", &n);
        if (!n) break;

        match = 0;
        check.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            if (x > y) swap(x, y);
            if (check[x][y]) {
                match += 2;
                check[x][y] = false;
            }
            else
                check[x][y] = true;
        }

        if (match == n)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
