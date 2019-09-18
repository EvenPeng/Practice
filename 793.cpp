#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int main(void)
{
    int cases;
    scanf("%d", &cases);

    char str[256];
    int  n, succ, unsucc, s, d, m;
    scanf("%d", &n);
    while (cases-- > 0) {
        succ   = 0;
        unsucc = 0;

        vector<int> table(n);
        for (int i = 0; i < n; i++)
            table[i] = i;

        while (scanf("%s", str) != EOF) {
            if (str[0] == 'c') {
                scanf("%d %d", &s, &d);
                s--;
                d--;
                m = min(table[s], table[d]);

                table[table[s]] = min(table[table[s]], m);
                table[table[d]] = min(table[table[d]], m);

                table[s] = m;
                table[d] = m;
                for (int i = 1; i < n; i++)
                    table[i] = table[table[i]];
            }
            else if (str[0] == 'q') {
                scanf("%d %d", &s, &d);
                if (s == d)
                    succ++;
                else {
                    s--;
                    d--;
                    if (table[s] == table[d])
                        succ++;
                    else
                        unsucc++;
                }
            }
            else
                break;
        }

        printf("%d,%d\n", succ, unsucc);
        if (cases) {
            printf("\n");
            n = atoi(str);
        }
    }

    return 0;
}
