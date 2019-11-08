#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <string>

struct Letter {
    char c;
    int  count;
};

bool sort_letter(const Letter &x, const Letter &y)
{
    return x.count == y.count ? x.c < y.c : x.count > y.count;
}

int main(void)
{
    int                    num_cases;
    std::string            buffer;
    std::array<Letter, 26> letter;

    getline(std::cin, buffer);
    num_cases = std::stoi(buffer);
    while (num_cases--) {
        for (int i = 0; i < 26; ++i) {
            letter[i].c     = 'a' + i;
            letter[i].count = 0;
        }

        getline(std::cin, buffer);
        for (const auto &c : buffer) {
            if (isalpha(c)) {
                ++letter[int(tolower(c) - 'a')].count;
            }
        }

        std::sort(letter.begin(), letter.end(), sort_letter);

        std::cout << letter[0].c;
        for (int i = 1; i < 26 && letter[i].count == letter[i - 1].count; ++i) {
            std::cout << letter[i].c;
        }
        std::cout << std::endl;
    }

    return 0;
}
