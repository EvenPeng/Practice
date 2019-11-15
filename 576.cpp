#include <iostream>
#include <string>

inline bool is_syllable(const char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main(void)
{
    bool        last;
    int         i, count;
    std::string buffer;

    while (1) {
        getline(std::cin, buffer);
        if (buffer == "e/o/i") break;

        i     = 0;
        count = 0;
        last  = false;
        while (buffer[i] != '/') {
            if (is_syllable(buffer[i])) {
                if (!last) ++count;
                last = true;
            }
            else {
                last = false;
            }
            ++i;
        }

        if (count != 5) {
            std::cout << 1 << std::endl;
            continue;
        }

        ++i;
        count = 0;
        last  = false;
        while (buffer[i] != '/') {
            if (is_syllable(buffer[i])) {
                if (!last) ++count;
                last = true;
            }
            else {
                last = false;
            }
            ++i;
        }

        if (count != 7) {
            std::cout << 2 << std::endl;
            continue;
        }

        ++i;
        count = 0;
        last  = false;
        while (i < buffer.size()) {
            if (is_syllable(buffer[i])) {
                if (!last) ++count;
                last = true;
            }
            else {
                last = false;
            }
            ++i;
        }

        if (count != 5) {
            std::cout << 3 << std::endl;
            continue;
        }

        std::cout << 'Y' << std::endl;
    }

    return 0;
}
