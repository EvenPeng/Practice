#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

long maxp(long *vec, int len)
{
    if (len == 1) return vec[0];

    long v, w, ans = 0;

    // all
    v = vec[0];
    for (int i = 1; i < len; ++i)
        v *= vec[i];

    if (v < 0) {
        w = v;
        for (int i = 0; w < 0 && i < len; ++i)
            w /= vec[i];
        ans = max(ans, w);
        w   = v;
        for (int i = len - 1; w < 0 && i > -1; --i)
            w /= vec[i];
        ans = max(ans, w);
        return ans;
    }
    else
        return v;
}

int main(void)
{
    int  T, n, len;
    long vec[18], ans;

    T = 0;
    while (scanf("%d", &n) != EOF) {
        ans = 0;
        len = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%ld", &vec[len]);
            if (vec[len] == 0) {
                ans = max(ans, maxp(vec, len));
                len = 0;
                continue;
            }
            if (len > 1 && vec[len] > 0 && vec[len - 1] > 0)
                vec[len - 1] *= vec[len];
            else
                len++;
        }
        ans = max(ans, maxp(vec, len));

        printf("Case #%d: The maximum product is %ld.\n\n", ++T, ans);
    }

    return 0;
}
