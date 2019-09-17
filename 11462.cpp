#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    bool first;
    int  age[100], times, i, j, index;

    while (true) {
        scanf("%d", &times);
        if (times < 1) break;

        memset(age, 0, sizeof(int) * 100);
        for (i = 0; i < times; ++i) {
            scanf("%d", &index);
            age[index]++;
        }

        first = true;
        for (i = 1; i < 100; ++i)
            for (j = 0; j < age[i]; ++j)
                if (!first)
                    printf(" %d", i);
                else {
                    first = false;
                    printf("%d", i);
                }
        printf("\n");
    }

    return 0;
}
