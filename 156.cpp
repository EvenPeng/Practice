#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct word {
    char arr[30], label[30];
    int  num, l;
};

word list[10001];
int  lenL;

int search(char *tmp)
{
    int i = -1;
    int j = lenL;
    int m, cmp;

    while (j - i > 1) {
        m   = (i + j) / 2;
        cmp = strcmp(tmp, list[m].label);
        if (cmp < 0)
            j = m;
        else if (cmp > 0)
            i = m;
        else
            return m;
    }

    return -1;
}

void sortD(int head, int len)
{
    int  i = head;
    int  j = head + len - 1;
    char pivot[30];
    word tmpW;

    if (len < 2) return;
    memcpy(pivot, list[head + len / 2].label, sizeof(char) * 30);

    while (true) {
        while (strcmp(list[i].label, pivot) < 0)
            ++i;
        while (strcmp(list[j].label, pivot) > 0)
            --j;
        if (i >= j) break;

        memcpy(&tmpW, list + i, sizeof(word));
        memcpy(list + i, list + j, sizeof(word));
        memcpy(list + j, &tmpW, sizeof(word));
    }

    sortD(head, i - head);
    sortD(i, len - i + head);
}

void sortF(int head, int len)
{
    int  i = head;
    int  j = head + len - 1;
    char pivot[30];
    word tmpW;

    if (len < 2) return;
    memcpy(pivot, list[head + len / 2].arr, sizeof(char) * 30);

    while (true) {
        while (strcmp(list[i].arr, pivot) < 0)
            ++i;
        while (strcmp(list[j].arr, pivot) > 0)
            --j;
        if (i >= j) break;

        memcpy(&tmpW, list + i, sizeof(word));
        memcpy(list + i, list + j, sizeof(word));
        memcpy(list + j, &tmpW, sizeof(word));
    }

    sortF(head, i - head);
    sortF(i, len - i + head);
}

int main(void)
{
    bool first;
    int  len, index;
    char c, tmpS[30], tmpL[30];

    lenL = 0;

    while (true) {
        scanf("%c", &c);

        len   = 0;
        first = true;
        while (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
            if (first) {
                memset(tmpS, '\0', sizeof(char) * 30);
                memset(tmpL, '\0', sizeof(char) * 30);
                first = false;
            }
            tmpS[len] = c;
            if ('A' <= c && c <= 'Z') c += 'a' - 'A';
            tmpL[len++] = c;
            scanf("%c", &c);
        }

        if (len > 0) {
            sort(tmpL, tmpL + len);
            index = search(tmpL);
            if (index < 0) {
                list[lenL].l   = len;
                list[lenL].num = 1;
                memcpy(list[lenL].arr, tmpS, sizeof(char) * 30);
                memcpy(list[lenL].label, tmpL, sizeof(char) * 30);
                lenL++;
                sortD(0, lenL);
            }
            else
                list[index].num++;
        }

        if (c == '#') break;
    }

    sortF(0, lenL);
    for (len = 0; len < lenL; ++len)
        if (list[len].num == 1) printf("%s\n", list[len].arr);

    return 0;
}
