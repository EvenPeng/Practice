/* check constraints by bit manipulations */
#include <algorithm>
#include <array>
#include <iostream>
#include <string>

int                 num_alpha, seen;
std::array<int, 26> alphabet, constraints;
std::string         output;

void print(const int count)
{
    if (count < num_alpha) {
        for (int i = 0; i < num_alpha; ++i) {
            if ((seen & (1 << alphabet[i])) &&
                !(constraints[alphabet[i]] & seen)) {
                seen ^= (1 << alphabet[i]);
                output[count] = char('a' + alphabet[i]);
                print(count + 1);
                seen ^= (1 << alphabet[i]);
            }
        }
    }
    else
        std::cout << output << std::endl;
}

int main(void)
{
    bool        first = true;
    std::string buffer;

    while (getline(std::cin, buffer)) {
        if (!first)
            std::cout << std::endl;
        else
            first = false;

        seen      = 0;
        num_alpha = 0;
        for (int i = 0; i < buffer.size(); i += 2) {
            alphabet[num_alpha] = int(buffer[i] - 'a');
            seen |= (1 << alphabet[num_alpha]);
            ++num_alpha;
        }
        std::sort(alphabet.begin(), alphabet.begin() + num_alpha);

        constraints.fill(0);
        getline(std::cin, buffer);
        for (int i = 0; i < buffer.size(); i += 4) {
            constraints[int(buffer[i + 2] - 'a')] |=
                (1 << int(buffer[i] - 'a'));
        }

        output.resize(num_alpha);
        print(0);
    }

    return 0;
}
