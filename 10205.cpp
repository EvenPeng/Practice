#include <array>
#include <iostream>
#include <string>

int main(void)
{
    int         num_cases, num_shuffles;
    std::string buffer;

    std::array<int, 53>                  curr, prev;
    std::array<std::array<int, 53>, 101> shuffles;

    std::array<std::string, 4> card_suit{
        {"Clubs", "Diamonds", "Hearts", "Spades"}};
    std::array<std::string, 13> card_value{{"Ace", "2", "3", "4", "5", "6", "7",
                                            "8", "9", "10", "Jack", "Queen",
                                            "King"}};

    getline(std::cin, buffer);
    num_cases = std::stoi(buffer);
    getline(std::cin, buffer);
    while (num_cases--) {
        for (int i = 1; i < 53; ++i)
            curr[i] = i;

        std::cin >> num_shuffles;
        for (int k = 1; k <= num_shuffles; ++k) {
            for (int i = 1; i < 53; ++i)
                std::cin >> shuffles[k][i];
        }
        getline(std::cin, buffer);

        while (1) {
            getline(std::cin, buffer);
            if (!buffer.size()) break;

            int k = std::stoi(buffer);
            std::swap(curr, prev);
            for (int i = 1; i < 53; ++i) {
                curr[i] = prev[shuffles[k][i]];
            }
        }

        for (int i = 1; i < 53; ++i) {
            std::cout << card_value[curr[i] % 13] << " of "
                      << card_suit[(curr[i] - 1) / 13] << std::endl;
        }

        if (num_cases) std::cout << std::endl;
    }

    return 0;
}
