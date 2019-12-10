#include <iostream>
#include <map>
#include <string>

int main(void)
{
    int         len;
    std::string dir, move;

    std::map<std::string, std::map<std::string, std::string>> forward = {
        {"+x", {{"+y", "+y"}, {"-y", "-y"}, {"+z", "+z"}, {"-z", "-z"}}},
        {"-x", {{"+y", "-y"}, {"-y", "+y"}, {"+z", "-z"}, {"-z", "+z"}}},
        {"+y", {{"+y", "-x"}, {"-y", "+x"}, {"+z", "+y"}, {"-z", "+y"}}},
        {"-y", {{"+y", "+x"}, {"-y", "-x"}, {"+z", "-y"}, {"-z", "-y"}}},
        {"+z", {{"+y", "+z"}, {"-y", "+z"}, {"+z", "-x"}, {"-z", "+x"}}},
        {"-z", {{"+y", "-z"}, {"-y", "-z"}, {"+z", "+x"}, {"-z", "-x"}}},
    };

    while (1) {
        std::cin >> len;
        if (!len) break;

        dir = "+x";
        for (int i = 1; i < len; ++i) {
            std::cin >> move;
            if (move == "No") continue;
            dir = forward[dir][move];
        }

        std::cout << dir << std::endl;
    }

    return 0;
}
