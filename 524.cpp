#include <cstdio>
#include <cstring>

using namespace std;

struct can {
    int len, list[11];
};

bool isPrime[40], check[21];
;
int n, list[20], cnt;
can cans[21];

void fill(int curr)
{
    int i, val, *p;
    val = list[curr];
    p   = cans[val].list;

    if (cnt < 1) {
        if (isPrime[1 + list[n - 1]]) {
            printf("1");
            for (i = 1; i < n; ++i)
                printf(" %d", list[i]);
            printf("\n");
        }
        return;
    }

    for (i = 0; i < cans[val].len; ++i)
        if (check[p[i]]) {
            list[curr + 1] = p[i];
            check[p[i]]    = false;
            cnt--;
            fill(curr + 1);
            check[p[i]] = true;
            cnt++;
        }
}

int main(void)
{
    int index, i, j;

    memset(check, true, sizeof(bool) * 21);
    memset(isPrime, true, sizeof(bool) * 40);
    for (i = 2; i < 40; ++i)
        if (isPrime[i])
            for (j = i + i; j < 40; j += i)
                isPrime[j] = false;

    for (i = 1; i <= 20; ++i) {
        cans[i].len = 0;
        for (j = i & 1 ? 2 : 3; j <= 22; j += 2)
            if (isPrime[i + j]) {
                cans[i].list[cans[i].len++] = j;
            }
    }

    index   = 0;
    list[0] = 1;
    while (scanf("%d", &n) != EOF) {
        for (i = 1; i <= n; ++i) {
            j = 0;
            while (cans[i].list[j] <= n)
                ++j;
            cans[i].len = j;
        }
        if (index > 0) printf("\n");
        printf("Case %d:\n", ++index);
        cnt = n - 1;
        fill(0);
    }

    return 0;
}
