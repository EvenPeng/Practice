#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    char word[5];
    int  sum, tmp, times, i;
    int  map[128], mapII[128];

    for (i = 0; i < 10; ++i) {
        map[i + '0']   = i;
        mapII[i + '0'] = (i * 2) / 10 + (i * 2) % 10;
    }

    scanf("%d", &times);

    while (times--) {
        sum = 0;
        for (i = 0; i < 4; ++i) {
            scanf("%s", word);
            sum += mapII[word[0]];
            sum += mapII[word[2]];
            sum += map[word[1]];
            sum += map[word[3]];
        }
        sum %= 10;
        if (!sum)
            printf("Valid\n");
        else
            printf("Invalid\n");
    }

    return 0;
}
