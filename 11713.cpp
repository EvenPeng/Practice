#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int  n;
    char sA[100], sB[100];
    bool same;

    scanf("%d", &n);
    while (n--) {
        scanf("%s %s", sA, sB);
        if (strlen(sA) != strlen(sB)) {
            printf("No\n");
        }
        else {
            same = true;
            for (int i = 0; same && i < strlen(sA); ++i) {
                switch (sA[i]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    same = sB[i] == 'a' || sB[i] == 'e' || sB[i] == 'o' || sB[i] == 'i' || sB[i] == 'u';
                    break;
                default:
                    same = sA[i] == sB[i];
                }
            }
            if (same)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
