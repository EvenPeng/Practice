#include <cstdio>
#include <cstring>

using namespace std;

char arr[2100][100];

void sortC(int beg, int len)
{
    int  i = 0;
    int  j = len - 1;
    char pivot[100];
    char tmpStr[100];

    if (len < 2) return;

    strcpy(pivot, arr[beg + len / 2]);

    while (true) {
        while (strcmp(arr[beg + i], pivot) < 0)
            ++i;
        while (strcmp(arr[beg + j], pivot) > 0)
            --j;
        if (i >= j) break;

        strcpy(tmpStr, arr[beg + i]);
        strcpy(arr[beg + i], arr[beg + j]);
        strcpy(arr[beg + j], tmpStr);

        i++;
        j--;
    }

    sortC(beg, i);
    sortC(beg + i, len - i);
}

bool compare(char *a, char *b)
{
    int i;

    if (strlen(a) != strlen(b)) return false;

    for (i = 0; i < strlen(a); ++i)
        if (a[i] != b[i]) return false;

    return true;
}

int main(void)
{
    int  len, n, i;
    char tmpStr[100];

    scanf("%d\n", &n);

    for (i = 0; i < n; ++i) {
        scanf("%s", arr[i]);
        gets(tmpStr);
    }

    sortC(0, n);

    len = 1;
    printf("%s ", arr[0]);
    for (i = 1; i < n; ++i, ++len)
        if (strcmp(arr[i], arr[i - 1]) != 0) {
            printf("%d\n", len);
            len = 0;
            printf("%s ", arr[i]);
        }
    printf("%d\n", len);

    return 0;
}
