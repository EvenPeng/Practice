#include <cstdio>

using namespace std;

int main(void)
{
    char c, arr[] = "22233344455566677778889999";
    int  index;

    while (scanf("%c", &c) != EOF)
        if ('A' <= c && c <= 'Z')
            printf("%c", arr[(int)(c - 'A')]);
        else
            printf("%c", c);

    return 0;
}
