#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int times, i, sq, head[51], cnt[51];

    cnt[1]  = 1;
    head[1] = 1;
    for (i = 2; i < 51; ++i) {
        sq      = i * i;
        cnt[i]  = sq - head[i - 1];
        head[i] = (sq + 1) / 2;
    }

    scanf("%d", &times);
    while (times--) {
        scanf("%d", &i);
        printf("%d\n", cnt[i]);
    }

    return 0;
}
