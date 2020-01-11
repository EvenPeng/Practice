#include <array>
#include <iostream>
#include <string>

int main(void)
{
    bool valid;
    int  num_case, size;

    std::ios::sync_with_stdio(false);

    std::string                            buffer;
    std::array<std::array<long, 300>, 300> matrix;

    std::cin >> num_case;
    for (int c = 1; c <= num_case; ++c) {
        std::cin >> buffer >> buffer >> size;
        valid = true;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cin >> matrix[i][j];
                valid &= matrix[i][j] >= 0;
            }
        }

        for (int i = 0; valid && i < size; ++i) {
            for (int j = i; valid && j < size; ++j) {
                valid = matrix[i][j] == matrix[size - 1 - i][size - 1 - j];
            }
        }

        if (valid)
            std::cout << "Test #" << c << ": Symmetric." << std::endl;
        else
            std::cout << "Test #" << c << ": Non-symmetric." << std::endl;
    }

    return 0;
}
