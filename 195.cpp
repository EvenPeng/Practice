#include <cstdio>
#include <cstring>

using namespace std;

int map[130];

void sortL(char *arr, int len)
{
    int  i     = 0;
    int  j     = len - 1;
    int  pivot = map[arr[len / 2]];
    char tmpC;

    if (len < 2) return;

    while (true) {
        while (map[arr[i]] < pivot)
            ++i;
        while (map[arr[j]] > pivot)
            --j;
        if (i >= j) break;

        memcpy(&tmpC, arr + i, sizeof(char));
        memcpy(arr + i, arr + j, sizeof(char));
        memcpy(arr + j, &tmpC, sizeof(char));

        i++;
        j--;
    }

    sortL(arr, i);
    sortL(arr + i, len - i);
}

int main(void)
{
    int  times, len, i, j, min;
    char list[10001], tmpC;

    for (i = 0; i < 26; ++i) {
        map[i + 'A'] = i * 2;
        map[i + 'a'] = i * 2 + 1;
    }

    scanf("%d", &times);

    while (times-- > 0) {
        scanf("%s", list);
        len = strlen(list);
        sortL(list, len);
        while (true) {
            printf("%s\n", list);
            i = len - 1;
            while (map[list[i]] <= map[list[i - 1]]) {
                i--;
                if (i < 1) break;
            }
            if (i < 1) break;
            min = i;
            i--;
            while (map[list[min]] <= map[list[i]]) {
                min++;
                if (min == len) break;
            }
            if (min < len) {
                for (j = min + 1; j < len; ++j)
                    if (map[list[j]] > map[list[i]] && map[list[j]] < map[list[min]]) min = j;
                memcpy(&tmpC, list + i, sizeof(char));
                memcpy(list + i, list + min, sizeof(char));
                memcpy(list + min, &tmpC, sizeof(char));
                sortL(list + i + 1, len - i - 1);
            }
            else
                sortL(list + i, len - i);
        }
    }

    return 0;
}
