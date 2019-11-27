#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Wine {
    std::string      name;
    int              num_pred;
    std::vector<int> successor;
};

int main(void)
{
    int         num_cases, num_wine, num_relation;
    int         p_idx, s_idx;
    std::string buffer;

    std::array<bool, 100>      seen;
    std::array<Wine, 100>      wine;
    std::map<std::string, int> name_to_index;

    num_cases = 0;
    while (getline(std::cin, buffer)) {
        name_to_index.clear();

        num_wine = std::stoi(buffer);
        for (int i = 0; i < num_wine; ++i) {
            getline(std::cin, wine[i].name);
            name_to_index[wine[i].name] = i;
            wine[i].num_pred            = 0;
            wine[i].successor.clear();
        }

        getline(std::cin, buffer);
        num_relation = std::stoi(buffer);
        for (int i = 0; i < num_relation; ++i) {
            getline(std::cin, buffer);
            auto sp_idx = buffer.find(' ');
            p_idx       = name_to_index[buffer.substr(0, sp_idx)];
            s_idx       = name_to_index[buffer.substr(sp_idx + 1)];
            wine[p_idx].successor.push_back(s_idx);
            ++wine[s_idx].num_pred;
        }

        seen.fill(false);
        std::cout << "Case #" << ++num_cases
                  << ": Dilbert should drink beverages in this order:";
        for (int k = 0; k < num_wine; ++k) {
            for (int i = 0; i < num_wine; ++i) {
                if (!seen[i] && !wine[i].num_pred) {
                    std::cout << " " << wine[i].name;
                    seen[i] = true;
                    for (const auto &j : wine[i].successor) {
                        --wine[j].num_pred;
                    }
                    break;
                }
            }
        }
        std::cout << "." << std::endl << std::endl;

        getline(std::cin, buffer);
    }

    return 0;
}
