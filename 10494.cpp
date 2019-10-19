#include <iostream>
#include <string>

int main(void)
{
    std::string        dividend, operation;
    unsigned long long divisor, remainder;
    bool               first;

    while (std::cin >> dividend >> operation >> divisor) {
        remainder = 0;
        if (operation == "/") {
            first = true;
            for (auto &d : dividend) {
                remainder *= 10;
                remainder += d - '0';
                if (!first) {
                    std::cout << remainder / divisor;
                }
                else if (remainder / divisor > 0) {
                    std::cout << remainder / divisor;
                    first = false;
                }
                remainder %= divisor;
            }
            if (first) std::cout << "0";
            std::cout << std::endl;
        }
        else {
            for (auto &d : dividend) {
                remainder *= 10;
                remainder += d - '0';
                remainder %= divisor;
            }
            std::cout << remainder << std::endl;
        }
    }

    return 0;
}
