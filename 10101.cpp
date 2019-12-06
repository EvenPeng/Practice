#include <iomanip>
#include <iostream>
#include <string>

int         width[] = {2, 2, 2, 1};
std::string unit[]  = {" kuti", " lakh", " hajar", " shata"};

bool show(const std::string &s, int i)
{
    bool printed;
    if (i < 0) i = 3;
    int digit;
    if (s.size() > width[i]) {
        printed = show(s.substr(0, s.size() - width[i]), i - 1);
        digit   = std::stoi(s.substr(s.size() - width[i]));
    }
    else {
        digit = std::stoi(s);
    }
    if (digit)
        std::cout << " " << digit << unit[i];
    else if (i == 0 && printed)
        std::cout << unit[i];

    return printed || digit;
}

int main(void)
{
    bool        printed;
    int         idx = 0, digit;
    std::string buffer;

    while (std::cin >> buffer) {
        std::cout << std::setw(4) << ++idx << ".";
        if (buffer.size() > 2) {
            printed = show(buffer.substr(0, buffer.size() - 2), 3);
            digit   = std::stoi(buffer.substr(buffer.size() - 2));
        }
        else {
            printed = false;
            digit = std::stoi(buffer);
        }
        if (digit)
            std::cout << " " << digit;
        else if (!printed)
            std::cout << " " << digit;
        std::cout << std::endl;
    }

    return 0;
}
