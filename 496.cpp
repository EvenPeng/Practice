#include <algorithm>
#include <iostream>
#include <set>
#include <string>

void parse_set(std::set<int> &set, std::string &line)
{
    set.clear();
    int i = 0;
    int j = 0;
    while (++j < line.size()) {
        if (line[j] == ' ') {
            set.insert(std::stoi(line.substr(i, j - i)));
            i = j + 1;
            j = i + 1;
        }
    }
    set.insert(std::stoi(line.substr(i, j - i)));
}

int main(void)
{
    std::string   line;
    std::set<int> setA, setB, intersection;

    while (std::getline(std::cin, line)) {
        parse_set(setA, line);

        std::getline(std::cin, line);
        parse_set(setB, line);

        intersection.clear();
        std::set_intersection(
            setA.begin(), setA.end(), setB.begin(), setB.end(),
            std::inserter(intersection, intersection.begin()));

        if (intersection.empty())
            std::cout << "A and B are disjoint" << std::endl;
        else if (setA == setB)
            std::cout << "A equals B" << std::endl;
        else if (setA == intersection)
            std::cout << "A is a proper subset of B" << std::endl;
        else if (setB == intersection)
            std::cout << "B is a proper subset of A" << std::endl;
        else
            std::cout << "I'm confused!" << std::endl;
    }

    return 0;
}
