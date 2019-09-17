#include <cmath>
#include <cstdio>

using namespace std;

int find(int x)
{
    int s = (int)sqrt((double)x);
    int l = s + 1;

    if (x == s * s) return s * 2 - 1;
    if (x <= s * l) return s * 2;
    return s * 2 + 1;
}

int main(void)
{
    int times, cnt, first, last;

    scanf("%d", &times);

    while (times-- > 0) {
        scanf("%d%d", &first, &last);
        cnt = last - first < 3 ? last - first : find(last - first);
        printf("%d\n", cnt);
    }

    return 0;
}
