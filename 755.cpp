#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Plate {
    std::string seq;
    int         num;
};

char ctoi(const char &c)
{
    switch (c) {
    case 'A':
    case 'B':
    case 'C':
        return '2';
    case 'D':
    case 'E':
    case 'F':
        return '3';
    case 'G':
    case 'H':
    case 'I':
        return '4';
    case 'J':
    case 'K':
    case 'L':
        return '5';
    case 'M':
    case 'N':
    case 'O':
        return '6';
    case 'P':
    case 'R':
    case 'S':
        return '7';
    case 'T':
    case 'U':
    case 'V':
        return '8';
    case 'W':
    case 'X':
    case 'Y':
        return '9';
    default:
        return c;
    }
}

std::string unify(const std::string &row)
{
    std::string res = "--------";
    int         i   = 0;

    for (const auto &c : row) {
        if (isalnum(c)) {
            res[i++] = ctoi(c);
            if (i == 3) ++i;
        }
    }

    return res;
}

int main(void)
{
    int                        num_cases;
    std::string                buffer;
    std::vector<Plate>         plates;
    std::map<std::string, int> count;

    getline(std::cin, buffer);
    num_cases = std::stoi(buffer);
    getline(std::cin, buffer);
    while (num_cases--) {
        count.clear();
        while (1) {
            getline(std::cin, buffer);
            if (buffer.size() < 1) break;
            ++count[unify(buffer)];
        }

        plates.clear();
        for (const auto &e : count) {
            if (e.second > 1) plates.push_back({e.first, e.second});
        }
        if (plates.size()) {
            for (const auto &p : plates) {
                std::cout << p.seq << " " << p.num << std::endl;
            }
        }
        else {
            std::cout << "No duplicates." << std::endl;
        }
        if (num_cases) std::cout << std::endl;
    }

    return 0;
}
