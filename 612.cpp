#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int  count[101], order[101];
char seq[101][52];

int comp(int x, int y)
{
    if (count[x] - count[y] == 0)
        return x - y;
    else
        return count[x] - count[y];
}

void sortD(int head, int len)
{
    int i = head;
    int j = head + len - 1;
    int tmpI, pivot = order[head + len / 2];

    if (len < 2) return;

    while (true) {
        while (comp(order[i], pivot) < 0)
            ++i;
        while (comp(order[j], pivot) > 0)
            --j;
        if (i >= j) break;

        tmpI       = order[i];
        order[i++] = order[j];
        order[j--] = tmpI;
    }

    sortD(head, i - head);
    sortD(i, len - i + head);
}

int main(void)
{
    int times, len, num, i, j, k, accu[4], label, sublen;
    int table[26];

    table['A' - 'A'] = 0;
    table['C' - 'A'] = 1;
    table['G' - 'A'] = 2;
    table['T' - 'A'] = 3;

    scanf("%d", &times);

    while (times-- > 0) {
        scanf("%d %d", &len, &num);

        for (i = 0; i < num; ++i) {
            order[i] = i;
            count[i] = 0;
            scanf("%s", &seq[i][0]);
        }

        for (i = 0; i < num; ++i) {
            for (j = 0; j < 4; ++j)
                accu[j] = 0;
            for (j = 0; j < len; j += sublen) {
                label  = table[seq[i][j] - 'A'];
                sublen = 1;
                while (j + sublen < len) {
                    if (seq[i][j] == seq[i][j + sublen])
                        sublen++;
                    else
                        break;
                }
                accu[label] += sublen;
                for (k = label + 1; k < 4; ++k)
                    count[i] += accu[k] * sublen;
            }
        }

        sortD(0, num);

        for (i = 0; i < num; ++i)
            printf("%s\n", seq[order[i]]);
        if (times > 0) printf("\n");
    }

    return 0;
}
