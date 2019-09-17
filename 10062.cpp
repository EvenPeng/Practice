#include <cstdio>
#include <cstring>

using namespace std;

struct node {
    int label, num;
};

int cmp(node *x, node *y)
{
    if (x->num - y->num != 0)
        return x->num - y->num;
    else
        return y->label - x->label;
}

void sortN(node *list, int len)
{
    int  i = 0;
    int  j = len - 1;
    node tmpS, pivot;

    if (len < 2) return;

    memcpy(&pivot, list + (len / 2), sizeof(node));

    while (true) {
        while (cmp(list + i, &pivot) < 0)
            ++i;
        while (cmp(list + j, &pivot) > 0)
            --j;
        if (i >= j) break;

        memcpy(&tmpS, list + i, sizeof(node));
        memcpy(list + i, list + j, sizeof(node));
        memcpy(list + j, &tmpS, sizeof(node));
        i++;
        j--;
    }

    sortN(list, i);
    sortN(list + i, len - i);
}

int main(void)
{
    bool first;
    char c;
    int  i, len, cnt[129];
    node list[100];

    first = true;
    memset(cnt + 32, 0, sizeof(int) * 96);
    while (scanf("%c", &c) != EOF) {
        if (32 <= c && c < 128) {
            cnt[c]++;
        }
        else {
            if (!first)
                printf("\n");
            else
                first = false;
            len = 0;
            for (i = 32; i < 128; ++i)
                if (cnt[i] > 0) {
                    list[len].label = i;
                    list[len].num   = cnt[i];
                    len++;
                }
            sortN(list, len);
            for (i = 0; i < len; ++i)
                printf("%d %d\n", list[i].label, list[i].num);
            memset(cnt + 32, 0, sizeof(int) * 96);
        }
    }

    return 0;
}
