#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    bool        valid, matched;
    std::string buffer;

    std::array<int, 26>              count;
    std::vector<std::string>         words;
    std::vector<std::array<int, 26>> dict;

    while (1) {
        std::cin >> buffer;
        if (buffer == "XXXXXX") break;

        words.push_back(buffer);
    }
    std::sort(words.begin(),words.end());

    for (int i = 0; i < words.size(); ++i) {
        count.fill(0);
        for (auto const &c : words[i])
            ++count[int(c - 'a')];
        dict.push_back(count);
    }

    while (1) {
        std::cin >> buffer;
        if (buffer == "XXXXXX") break;

        count.fill(0);
        for (auto const &c : buffer)
            ++count[int(c - 'a')];

        valid = false;
        for (int i = 0; i < words.size(); ++i) {
            matched = true;
            for (int j = 0; matched && j < 26; ++j) {
                matched = count[j] == dict[i][j];
            }
            if (matched) {
                std::cout << words[i] << std::endl;
                valid = true;
            }
        }

        if (!valid) {
            std::cout << "NOT A VALID WORD" << std::endl;
        }
        std::cout << "******" << std::endl;
    }

    return 0;
}
