#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    int              T, n, but, top, move[200], len;
    string           origin[200], target[200];
    map<string, int> table;

    scanf("%d\n", &T);
    while (T--) {
        table.clear();
        scanf("%d\n", &n);
        for (int i = n - 1; i > -1; --i)
            getline(cin, origin[i]);
        for (int i = n - 1; i > -1; --i) {
            getline(cin, target[i]);
            table[target[i]] = i;
        }

        but = 0;
        top = n - 1;
        len = 0;
        for (int i = 0; i < n; ++i)
            if (table[origin[i]] == but) {
                but++;
            }
            else if (table[origin[i]] > but) {
                top         = table[origin[i]];
                move[len++] = table[origin[i]];
            }
            else if (table[origin[i]] > top) {
                move[len++] = table[origin[i]];
            }

        sort(move, move + len);

        for (int i = 0; i < len; ++i)
            printf("%s\n", target[move[i]].c_str());
        printf("\n");
    }

    return 0;
}
