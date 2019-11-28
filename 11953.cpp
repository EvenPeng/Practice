#include <array>
#include <iostream>
#include <string>

int main(void)
{
    int num_cases, width, count;

    std::array<std::string, 100> field;

    std::cin >> num_cases;
    for (int k = 1; k <= num_cases; ++k) {
        std::cin >> width;
        for (int i = 0; i < width; ++i) {
            std::cin >> field[i];
        }

        count = 0;
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < width; ++j) {
                if (field[i][j] == 'x') {
                    field[i][j] = '@';
                    ++count;
                    for (int l = i - 1; l > -1 && field[l][j] != '.'; --l)
                        field[l][j] = '@';
                    for (int l = j - 1; l > -1 && field[i][l] != '.'; --l)
                        field[i][l] = '@';
                    for (int l = i + 1; l < width && field[l][j] != '.'; ++l)
                        field[l][j] = '@';
                    for (int l = j + 1; l < width && field[i][l] != '.'; ++l)
                        field[i][l] = '@';
                }
            }
        }

        std::cout << "Case " << k << ": " << count << std::endl;
    }

    return 0;
}
