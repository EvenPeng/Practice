#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    char word[100010];
    int  L, R, num[100010];
    int  i, len, index;

    while (scanf("%s", word) != EOF) {
        len = strlen(word);
        L   = 50000;
        R   = 50000;

        if (word[0] != '[' && word[0] != ']') num[R++] = 0;

        for (i = 0; i < len - 1; ++i)
            if (word[i] == '[' && (word[i + 1] != '[' || word[i + 1] != ']')) {
                num[--L] = i + 1;
            }
            else if (word[i] == ']' && (word[i + 1] != '[' || word[i + 1] != ']')) {
                num[R++] = i + 1;
            }

        for (i = L; i < R; ++i) {
            index = num[i];
            while (index < len && word[index] != ']' && word[index] != '[')
                printf("%c", word[index++]);
        }
        printf("\n");
    }

    return 0;
}
