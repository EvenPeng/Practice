#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    bool   halt;
    int    T;
    string ram[1000], op;
    int    reg[10], len, d, n, cnt, ptr;

    scanf("%d\n", &T);
    while (T--) {
        len = 0;
        while (1) {
            getline(cin, ram[len]);
            if (ram[len] == "")
                break;
            else
                len++;
        }
        len++;

        halt = false;
        cnt  = 0;
        ptr  = 0;
        memset(reg, 0, sizeof(reg));
        while (1) {
            op = ram[ptr++];
            if (halt) break;
            d = int(op[1] - '0');
            n = int(op[2] - '0');
            cnt++;
            switch (op[0]) {
            case '1':
                halt = !d && !n;
            case '2':
                reg[d] = n;
                break;
            case '3':
                reg[d] += n;
                reg[d] %= 1000;
                break;
            case '4':
                reg[d] *= n;
                reg[d] %= 1000;
                break;
            case '5':
                reg[d] = reg[n];
                break;
            case '6':
                reg[d] += reg[n];
                reg[d] %= 1000;
                break;
            case '7':
                reg[d] *= reg[n];
                reg[d] %= 1000;
                break;
            case '8':
                reg[d] = atoi(ram[reg[n]].c_str());
                break;
            case '9':
                ram[reg[n]] = to_string(reg[d]);
                break;
            case '0':
                if (reg[n]) ptr = reg[d];
                break;
            }
        }
        printf("%d\n", cnt);
        if (T) printf("\n");
    }

    return 0;
}
