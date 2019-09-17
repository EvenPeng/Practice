#include <cstdio>
#include <cstring>

using namespace std;

int map[128];

void post(char *st1, char *st2, int len)
{
    int label1, label2, lenB, lenC;

    if (len == 1) {
        printf("%c", st1[0]);
        return;
    }

    lenB   = 0;
    label1 = 1 << map[st1[lenB]];
    label2 = 1 << map[st2[lenB]];
    while (label1 != label2) {
        lenB++;
        label1 += 1 << map[st1[lenB]];
        label2 += 1 << map[st2[lenB]];
    }

    lenC = len - lenB - 1;
    if (lenB > 0) post(st1 + 1, st2, lenB);
    if (lenC > 0) post(st1 + lenB + 1, st2 + lenB + 1, lenC);
    printf("%c", st1[0]);
}

int main(void)
{
    char st1[30], st2[30];
    int  i;

    for (i = 0; i < 26; ++i)
        map['A' + i] = i;
    while (scanf("%s %s", st1, st2) != EOF) {
        post(st1, st2, strlen(st1));
        printf("\n");
    }

    return 0;
}
