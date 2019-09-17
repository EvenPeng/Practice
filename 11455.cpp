#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int times, i, list[4];

    scanf("%d", &times);

    while (times--) {
        for (i = 0; i < 4; ++i)
            scanf("%d", list + i);
        sort(list, list + 4);
        if (list[0] == list[1] && list[2] == list[3]) {
            if (list[1] == list[2])
                printf("square\n");
            else
                printf("rectangle\n");
        }
        else if (list[3] < list[0] + list[1] + list[2])
            printf("quadrangle\n");
        else
            printf("banana\n");
    }

    return 0;
}
