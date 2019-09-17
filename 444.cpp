#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char in[100000], out[100000];
    int  lenL, lenO, i;

    while (gets(in)) {
        lenL = strlen(in);
        lenO = 0;
        if ('0' <= in[0] && in[0] <= '9') {
            for (i = 0; i < lenL; ++lenO) {
                out[lenO] = in[i++] - '0';
                out[lenO] += (in[i++] - '0') * 10;
                if (out[lenO] < 23) out[lenO] += (in[i++] - '0') * 100;
            }
            for (i = lenO - 1; i > -1; --i)
                printf("%c", out[i]);
            printf("\n");
        }
        else {
            for (i = 0; i < lenL; ++i) {
                if (in[i] > 99) out[lenO++] = '0' + (in[i] / 100);
                out[lenO++] = '0' + ((in[i] % 100) / 10);
                out[lenO++] = '0' + (in[i] % 10);
            }
            for (i = lenO - 1; i > -1; --i)
                printf("%c", out[i]);
            printf("\n");
        }
    }

    return 0;
}
