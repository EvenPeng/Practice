#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    bool                   first;
    long long              x, fact, sum;
    std::string            buffer;
    std::vector<long long> coef;

    while (getline(std::cin, buffer)) {
        if (!buffer.size()) break;

        coef.clear();
        for (int i = 0, j = 1;;) {
            if (j >= buffer.size()) {
                coef.insert(coef.begin(), std::stoll(buffer.substr(i)));
                break;
            }
            else if (buffer[j] == ' ') {
                coef.insert(coef.begin(), std::stoll(buffer.substr(i, j - i)));
                i = j + 1;
                j = i + 1;
            }
            else {
                ++j;
            }
        }

        getline(std::cin, buffer);
        first = true;
        for (int i = 0, j = 1;;) {
            if (j >= buffer.size()) {
                x    = std::stoll(buffer.substr(i));
                fact = 1;
                sum  = 0;
                for (auto const &c : coef) {
                    sum += fact * c;
                    fact *= x;
                }
                if (!first) std::cout << " ";
                std::cout << sum << std::endl;
                break;
            }
            else if (buffer[j] == ' ') {
                x    = std::stoll(buffer.substr(i, j - i));
                fact = 1;
                sum  = 0;
                for (auto const &c : coef) {
                    sum += fact * c;
                    fact *= x;
                }
                if (!first) std::cout << " ";
                std::cout << sum;
                i     = j + 1;
                j     = i + 1;
                first = false;
            }
            else {
                ++j;
            }
        }
    }

    return 0;
}
