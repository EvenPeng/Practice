#include <cstdio>

using namespace std;

char table[10] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

bool check(char x)
{
    int i, j, m;

    i = -1;
    j = 11;

    while (j - i > 1) {
        m = (i + j) / 2;
        if (x < table[m])
            j = m;
        else if (x > table[m])
            i = m;
        else
            return true;
    }

    return false;
}

int main(void)
{
    bool flag;
    char c, head;

    flag = true;
    while (scanf("%c", &c) != EOF) {
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
            if (flag) {
                flag = false;
                head = c;
                if (check(c)) printf("%c", c);
            }
            else
                printf("%c", c);
        }
        else {
            if (!flag) {
                if (!check(head)) printf("%c", head);
                printf("ay");
            }
            printf("%c", c);
            flag = true;
        }
    }

    return 0;
}
