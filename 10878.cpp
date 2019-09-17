#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char tmpS[12], c;

    gets(tmpS);
    while (true) {
        gets(tmpS);
        if (tmpS[0] == '_') break;
        c = 0;
        if (tmpS[2] == 'o') c += 1 << 6;
        if (tmpS[3] == 'o') c += 1 << 5;
        if (tmpS[4] == 'o') c += 1 << 4;
        if (tmpS[5] == 'o') c += 1 << 3;
        if (tmpS[7] == 'o') c += 1 << 2;
        if (tmpS[8] == 'o') c += 1 << 1;
        if (tmpS[9] == 'o') c += 1;
        printf("%c", c);
    }

    return 0;
}
