#include <cstdio>
#include <cstring>

using namespace std;

int  dollar[1001];
char str[1001][20];

void sortD(int *label, int len)
{
    int i = 0;
    int j = len - 1;
    int tmpI, pivot = label[len / 2];

    if (len < 2) return;

    while (true) {
        while (strcmp(&str[label[i]][0], &str[pivot][0]) < 0)
            ++i;
        while (strcmp(&str[label[j]][0], &str[pivot][0]) > 0)
            --j;
        if (i >= j) break;
        tmpI       = label[i];
        label[i++] = label[j];
        label[j--] = tmpI;
    }

    sortD(label, i);
    sortD(label + i, len - i);
}

int main(void)
{
    char word[20];
    int  m, n, i, j, con;
    int  label[1001], head[26], len[26];
    long sum;

    while (scanf("%d %d\n", &m, &n) != EOF) {
        for (i = 0; i < m; ++i) {
            label[i] = i;
            scanf("%s %d\n", &str[i][0], dollar + i);
        }

        sortD(label, m);
        for (i = 0; i < 26; ++i) {
            head[i] = 0;
            len[i]  = 0;
        }
        head[str[label[0]][0] - 'a'] = 0;
        len[str[label[0]][0] - 'a']++;
        for (i = 1; i < m; ++i) {
            len[str[label[i]][0] - 'a']++;
            if (str[label[i]][0] != str[label[i - 1]][0]) head[str[label[i]][0] - 'a'] = i;
        }

        sum = 0;
        while (true) {
            scanf("%s", word);
            if (word[0] == '.') {
                printf("%ld\n", sum);
                if (!--n)
                    break;
                else
                    sum = 0;
            }
            else {
                i = head[word[0] - 'a'] - 1;
                j = head[word[0] - 'a'] + len[word[0] - 'a'];
                while (j - i > 1) {
                    m   = (i + j) / 2;
                    con = strcmp(word, &str[label[m]][0]);
                    if (con < 0)
                        j = m;
                    else if (con > 0)
                        i = m;
                    else
                        break;
                }
                m = (i + j) / 2;
                if (strcmp(word, &str[label[m]][0]) == 0) sum += dollar[label[m]];
            }
        }
    }

    return 0;
}
