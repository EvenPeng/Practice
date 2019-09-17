#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int sh, sm, eh, em;

    while (true) {
        scanf("%d %d %d %d", &sh, &sm, &eh, &em);
        if (sh + sm + eh + em == 0) break;

        em += eh * 60;
        sm += sh * 60;
        if (sm > em) em += 60 * 24;

        printf("%d\n", em - sm);
    }

    return 0;
}
