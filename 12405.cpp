#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int  T, n, cnt;
    char vec[101];

    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d %s", &n, vec);

        cnt = 0;
        for (int i = 0; i < n; ++i)
            if (vec[i] == '.') {
                i += 2;
                cnt++;
            }

        printf("Case %d: %d\n", t, cnt);
    }

    return 0;
}
