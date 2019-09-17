#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int  l, r, d, min, tmp;
    char highway[2000000];

    while (1) {
        scanf("%d", &l);
        if (l < 1) break;

        scanf("%s", highway);

        min = l;
        r   = -1;
        d   = -1;

        for (int i = 0; i < l; ++i) {
            if (highway[i] != '.') {
                if (highway[i] == 'R')
                    r = i;
                else if (highway[i] == 'D')
                    d = i;
                else {
                    min = 0;
                    break;
                }
                if (r > -1 && d > -1) {
                    tmp = abs(r - d);
                    if (tmp < min) {
                        min = tmp;
                        if (min < 1) break;
                    }
                }
            }
        }

        printf("%d\n", min);
    }

    return 0;
}
