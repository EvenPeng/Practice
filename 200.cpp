#include <cstdio>
#include <cstring>

using namespace std;

bool check[26], table[26][26];
int  order[26], map[130];

int main(void)
{
    bool  flag;
    char *pA, *pB, *tmpP, strA[30], strB[30], tmpC;
    int   i, j, list[26], len, lenA, lenB, acc, cnt;

    for (i = 0; i < 26; ++i)
        map[i + 'A'] = i;

    acc  = 0;
    lenA = 0;
    lenB = 0;
    pA   = strA;
    pB   = strB;
    memset(check, false, sizeof(bool) * 26);
    memset(table, false, sizeof(bool) * 26 * 26);
    memset(order, -1, sizeof(int) * 26);
    while (scanf("%s", pA) != EOF) {
        if (pA[0] != '#') {
            lenA = strlen(pA);
            if (lenB > 0) {
                for (i = 0; pA[i] == pB[i]; ++i)
                    check[map[pA[i]]] = true;
                if (i < lenA && i < lenB) {
                    table[map[pB[i]]][map[pA[i]]] = true;
                    check[map[pB[i]]]             = true;
                    check[map[pA[i]]]             = true;
                }
            }

            tmpP = pA;
            pA   = pB;
            pB   = tmpP;
            lenB = lenA;
        }
        else {
            len = 0;
            for (i = 0; i < 26; ++i)
                if (check[i]) list[len++] = i;
            while (len > 0) {
                for (i = 0; i < len; ++i) {
                    flag = true;
                    for (j = 0; flag && j < 26; ++j)
                        flag &= !table[j][list[i]];
                    if (flag) {
                        printf("%c", 'A' + list[i]);
                        for (j = 0; j < 26; ++j)
                            table[list[i]][j] = false;
                        tmpC          = list[len - 1];
                        list[len - 1] = list[i];
                        list[i]       = tmpC;
                        len--;
                        break;
                    }
                }
            }
            printf("\n");
            acc  = 0;
            lenA = 0;
            lenB = 0;
            memset(check, false, sizeof(bool) * 26);
            memset(table, false, sizeof(bool) * 26 * 26);
            memset(order, -1, sizeof(int) * 26);
        }
    }

    return 0;
}
