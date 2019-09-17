#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int  i, j, cases, cnt[101][101];
    char M[101], F[101];

    cases = 0;
    while (gets(M) != NULL && M[0] != '#') {
        gets(F);
        if (strlen(M) == 0 || strlen(F) == 0) {
            printf("Case #%d: you can visit at most 0 cities.\n", ++cases);
            continue;
        }
        cnt[0][0] = M[0] == F[0] ? 1 : 0;
        for (i = 1; i < strlen(M); ++i)
            cnt[i][0] = cnt[i - 1][0] > 0 || M[i] == F[0] ? 1 : 0;
        for (j = 1; j < strlen(F); ++j)
            cnt[0][j] = cnt[0][j - 1] > 0 || M[0] == F[j] ? 1 : 0;
        for (i = 1; i < strlen(M); ++i)
            for (j = 1; j < strlen(F); ++j) {
                cnt[i][j] = M[i] == F[j] ? cnt[i - 1][j - 1] + 1 : cnt[i - 1][j - 1];
                if (cnt[i - 1][j] > cnt[i][j]) cnt[i][j] = cnt[i - 1][j];
                if (cnt[i][j - 1] > cnt[i][j]) cnt[i][j] = cnt[i][j - 1];
            }
        printf("Case #%d: you can visit at most %d cities.\n", ++cases, cnt[i - 1][j - 1]);
    }

    return 0;
}
