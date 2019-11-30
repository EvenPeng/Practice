#include <iostream>
#include <map>
#include <string>

int main(void)
{
    std::string                 buffer;
    std::map<std::string, bool> exist;

    while (std::cin >> buffer) {
        exist.clear();

        for (int i = 0; i < buffer.size(); ++i) {
            exist[buffer.substr(i, 1)] = true;
            for (int j = i - 1, k = i + 1; j > -1 && k < buffer.size();
                 --j, ++k) {
                if (buffer[j] == buffer[k])
                    exist[buffer.substr(j, k - j + 1)] = true;
                else
                    break;
            }

            for (int j = i, k = i + 1; j > -1 && k < buffer.size(); --j, ++k) {
                if (buffer[j] == buffer[k])
                    exist[buffer.substr(j, k - j + 1)] = true;
                else
                    break;
            }
        }

        std::cout << "The string '" << buffer << "' contains " << exist.size()
                  << " palindromes." << std::endl;
    }

    return 0;
}
