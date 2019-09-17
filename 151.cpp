#include <cstdio>

using namespace std;

bool arr[100];
int  n;

bool check(int m)
{
    int i, index, len;

    index  = 0;
    arr[0] = false;
    for (i = 1; i < n; ++i)
        arr[i] = true;

    while (index != 12) {
        len = m;
        while (len > 0) {
            index = (index + 1) % n;
            if (arr[index]) len--;
        }
        arr[index] = false;
    }

    for (i = 0; i < n; ++i)
        if (arr[i]) return false;
    return true;
}

int main(void)
{
    int i, m;

    while (scanf("%d", &n) != EOF && n > 0) {
        m = 0;
        while (!check(++m))
            ;
        printf("%d\n", m);
    }

    return 0;
}
