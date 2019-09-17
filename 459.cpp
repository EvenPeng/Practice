#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    bool flag[26];
    int  times, i, cnt, map[128], label[26], old, upd, len;
    char org, x, y, tmpS[10];

    for (i = 0; i < 26; ++i)
        map['A' + i] = i;
    scanf("%d\n", &times);
    scanf("%s", tmpS);

    while (times-- > 0) {
        sscanf(tmpS, "%c", &org);

        len = map[org] + 1;
        for (i = 0; i < len; ++i)
            label[i] = i;

        while (scanf("%s", tmpS) != EOF) {
            if (tmpS[1] == '\0') break;
            sscanf(tmpS, "%c%c", &x, &y);
            if (label[map[x]] > label[map[y]]) {
                old = label[map[x]];
                upd = label[map[y]];
            }
            else {
                old = label[map[y]];
                upd = label[map[x]];
            }
            if (old != upd)
                for (i = 0; i < len; ++i)
                    if (label[i] == old) label[i] = upd;
        }
        cnt = 0;
        memset(flag, true, sizeof(bool) * 26);
        for (i = 0; i < len; ++i)
            if (flag[label[i]]) {
                cnt++;
                flag[label[i]] = false;
            }
        if (times > 0)
            printf("%d\n\n", cnt);
        else
            printf("%d\n", cnt);
    }

    return 0;
}
