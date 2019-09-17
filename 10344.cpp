#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int list[5];

bool verify(int v, int x)
{
    if (x < 4) {
        if (verify(v + list[x], x + 1)) return true;
        if (verify(v - list[x], x + 1)) return true;
        if (verify(v * list[x], x + 1)) return true;
    }
    else {
        if (v + list[x] == 23) return true;
        if (v - list[x] == 23) return true;
        if (v * list[x] == 23) return true;
    }

    return false;
}

int main(void)
{
    bool flag;
    int  i;

    while (true) {
        flag = true;
        for (i = 0; i < 5; ++i) {
            scanf("%d", list + i);
            flag &= list[i] == 0;
        }
        if (flag) break;

        flag = false;

        sort(list, list + 5);

        do {
            if (verify(list[0], 1)) {
                flag = true;
                break;
            }
        } while (next_permutation(list, list + 5));

        if (flag)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }

    return 0;
}
