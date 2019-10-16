#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

size_t width = 81;
char * land[31];

void paint(int x, int y)
{
    land[x][y] = '#';
    if (land[x + 1][y] == ' ') paint(x + 1, y);
    if (land[x - 1][y] == ' ') paint(x - 1, y);
    if (land[x][y + 1] == ' ') paint(x, y + 1);
    if (land[x][y - 1] == ' ') paint(x, y - 1);
}

int main(void)
{
    for (int i = 0; i < 31; ++i)
        land[i] = (char *)malloc(sizeof(char) * width);

    bool found;
    int  T, x, y, n;
    scanf("%d\n", &T);
    while (T--) {
        n     = 0;
        found = false;
        while (1) {
            getline(&land[n], &width, stdin);
            if (land[n][0] == '_') break;
            if (!found) {
                for (int i = 1; i < strlen(land[n]) - 1; ++i)
                    if (land[n][i] == '*') {
                        found = true;
                        x     = n;
                        y     = i;
                    }
            }
            ++n;
        }

        paint(x, y);
        for (int i = 0; i < n; ++i)
            printf("%s", land[i]);
        printf("%s", land[n]);
    }

    return 0;
}
