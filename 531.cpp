#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

int main(void)
{
    std::map<std::string, int> exist;
    std::string                textA[100], textB[100], ans[100];
    int                        lenA = 0, lenB = 0, lenT;
    int                        count[100][100];

    while (std::cin >> textA[0]) {
        exist.clear();
        exist[textA[0]] = true;
        lenA            = 1;
        while (1) {
            std::cin >> textA[lenA];
            if (textA[lenA] == "#") break;
            exist[textA[lenA++]] = 1;
        }
        lenB = 0;
        while (1) {
            std::cin >> textB[lenB];
            if (textB[lenB] == "#") break;
            if (exist[textB[lenB]]) {
                exist[textB[lenB++]] = 2;
            }
        }
        // eliminate useless text in textA
        lenT = 0;
        for (int i = 0; i < lenA; ++i) {
            if (exist[textA[i]] == 2) {
                textA[lenT] = textA[i];
                memset(count[lenT], 0, sizeof(count[lenT]));
                ++lenT;
            }
        }
        lenA = lenT;

        count[0][0] = textA[0] == textB[0] ? 1 : 0;
        for (int j = 1; j < lenB; ++j) {
            count[0][j] = count[0][j - 1];
            if (textA[0] == textB[j]) count[0][j] = 1;
        }
        for (int i = 1; i < lenA; ++i) {
            count[i][0] = count[i - 1][0];
            if (textA[i] == textB[0]) count[i][0] = 1;
            for (int j = 1; j < lenB; ++j) {
                count[i][j] = std::max(count[i][j - 1], count[i - 1][j]);
                if (textA[i] == textB[j]) {
                    count[i][j] =
                        std::max(count[i][j], count[i - 1][j - 1] + 1);
                }
            }
        }

        lenT = count[lenA - 1][lenB - 1];
        for (int i = lenA - 1, j = lenB - 1; lenT && i > -1 && j > -1;
             --i, --j) {
            while (count[i][j] == count[i - 1][j])
                --i;
            while (count[i][j] == count[i][j - 1])
                --j;
            ans[--lenT] = textA[i];
        }

        std::cout << ans[0];
        for (int i = 1; i < count[lenA - 1][lenB - 1]; ++i)
            std::cout << " " << ans[i];
        std::cout << std::endl;
    }

    return 0;
}
