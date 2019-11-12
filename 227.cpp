#include <array>
#include <iostream>
#include <string>

int main(void)
{
    bool                       done, failed;
    int                        case_index = 0;
    int                        x, y;
    std::string                buffer;
    std::array<std::string, 5> puzzle;

    while (1) {
        getline(std::cin, puzzle[0]);
        if (puzzle[0].size() < 5) {
            if (puzzle[0][0] == 'Z')
                break;
            else
                puzzle[0].resize(5, ' ');
        }
        for (int i = 1; i < 5; ++i) {
            getline(std::cin, puzzle[i]);
            if (puzzle[i].size() < 5) puzzle[i].resize(5, ' ');
        }

        x = 0;
        y = 0;
        while (puzzle[x][y] != ' ') {
            ++x;
            y += x / 5;
            x %= 5;
        }

        done   = false;
        failed = false;
        while (!done) {
            getline(std::cin, buffer);
            for (const auto &c : buffer) {
                switch (c) {
                case 'A':
                    if (x - 1 > -1) {
                        puzzle[x][y] = puzzle[x - 1][y];
                        --x;
                        puzzle[x][y] = ' ';
                    }
                    else {
                        failed = true;
                    }
                    break;
                case 'B':
                    if (x + 1 < 5) {
                        puzzle[x][y] = puzzle[x + 1][y];
                        ++x;
                        puzzle[x][y] = ' ';
                    }
                    else {
                        failed = true;
                    }
                    break;
                case 'R':
                    if (y + 1 < 5) {
                        puzzle[x][y] = puzzle[x][y + 1];
                        ++y;
                        puzzle[x][y] = ' ';
                    }
                    else {
                        failed = true;
                    }
                    break;
                case 'L':
                    if (y - 1 > -1) {
                        puzzle[x][y] = puzzle[x][y - 1];
                        --y;
                        puzzle[x][y] = ' ';
                    }
                    else {
                        failed = true;
                    }
                    break;
                case '0':
                    done = true;
                    break;
                default:
                    failed = true;
                }
                if (done) break;
            }
        }

        if (case_index) std::cout << std::endl;
        std::cout << "Puzzle #" << ++case_index << ":" << std::endl;
        if (failed)
            std::cout << "This puzzle has no final configuration." << std::endl;
        else {
            for (const auto &line : puzzle) {
                std::cout << line[0];
                for (int i = 1; i < 5; ++i)
                    std::cout << " " << line[i];
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
