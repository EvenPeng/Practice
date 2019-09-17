#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char list[5000][100], map[130];

void sortL(int head, int len)
{
    int  i = head;
    int  j = head + len - 1;
    char tmpS[100], pivot[100];

    if (len < 2)
        return;
    else
        memcpy(pivot, list[head + len / 2], sizeof(char) * 100);

    while (true) {
        while (strcmp(list[i], pivot) < 0)
            ++i;
        while (strcmp(list[j], pivot) > 0)
            --j;
        if (i >= j) break;

        memcpy(tmpS, list[i], sizeof(char) * 100);
        memcpy(list[i++], list[j], sizeof(char) * 100);
        memcpy(list[j--], tmpS, sizeof(char) * 100);
    }

    sortL(head, i - head);
    sortL(i, len - i + head);
}

int main(void)
{
    char c, tmpS[100];
    int  lenL, lenS, i, j;

    for (i = 0; i < 26; ++i)
        map[i + 'A'] = i + 'a';

    lenL = 0;
    while (scanf("%c", &c) != EOF) {
        lenS = 0;
        while (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
            if (c < 'a') c = map[c];
            tmpS[lenS++] = c;
            scanf("%c", &c);
        }
        if (lenS > 0) {
            memcpy(list[lenL], tmpS, sizeof(char) * lenS);
            list[lenL++][lenS] = '\0';
            if (lenL == 5000) {
                sortL(0, lenL);
                i = 1;
                for (j = 1; j < lenL; ++j)
                    if (strcmp(list[j - 1], list[j]) != 0) memcpy(list[i++], list[j], sizeof(char) * 100);
                lenL = i;
            }
        }
    }

    sortL(0, lenL);
    printf("%s\n", list[0]);
    for (i = 1; i < lenL; ++i)
        if (strcmp(list[i - 1], list[i]) != 0) printf("%s\n", list[i]);

    return 0;
}
