#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char *inP, str[100000], ele[1000][1000];
    int   times, list[1000], len, i;
    int   read;

    scanf("%d\n", &times);

    while (times--) {
        gets(str);
        len = 0;
        inP = str;
        while (sscanf(inP, "%d%n", &list[len++], &read) == 1)
            inP += read;
        len--;
        gets(str);
        inP = str;
        for (i = 0; i < len; ++i) {
            sscanf(inP, "%s%n", &ele[list[i]][0], &read);
            inP += read;
        }
        for (i = 1; i <= len; ++i)
            printf("%s\n", ele[i]);
        if (times) printf("\n");
        gets(str);
    }

    return 0;
}
