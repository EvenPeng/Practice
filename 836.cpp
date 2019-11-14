#include <algorithm>
#include <array>
#include <iostream>
#include <string>

int count_ones(const std::string line, const int size, int start)
{
    int count = 0;

    while (start < size && line[start] == '1') {
        ++count;
        ++start;
    }

    return count;
}

int main(void)
{
    int                         num_cases, size, max_count, dx, dy;
    std::string                 buffer;
    std::array<std::string, 26> matrix;

    getline(std::cin, buffer);
    num_cases = std::stoi(buffer);
    getline(std::cin, buffer);
    while (num_cases--) {
        size = 0;
        while (getline(std::cin, matrix[size])) {
            if (matrix[size].size() == 0) break;
            ++size;
        }

        max_count = 0;
        for (int i = 0; max_count < (size - i) * size && i < size; ++i) {
            for (int j = 0; max_count < (size - i) * (size - j) && j < size;
                 ++j) {
                if (matrix[i][j] == '1') {
                    dx = 1;
                    dy = count_ones(matrix[i], size, j);
                    if (max_count < dx * dy) max_count = dx * dy;
                    while (i + dx < size && matrix[i + dx][j] == '1') {
                        dy = std::min(dy, count_ones(matrix[i + dx], size, j));
                        ++dx;
                        if (max_count < dx * dy) max_count = dx * dy;
                    }
                }
            }
        }

        std::cout << max_count << std::endl;
        if (num_cases) std::cout << std::endl;
    }

    return 0;
}
