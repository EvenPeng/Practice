#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Node {
    std::array<int, 52> child;
    std::vector<int>    id;
};

int main(void)
{
    int num_cases, num_query, table_size;

    std::map<char, int>     ctoi;
    std::array<bool, 1000>  exist;
    std::array<Node, 10000> table;
    std::string             str, query;

    for (int i = 0; i < 26; ++i) {
        ctoi['a' + i] = i;
        ctoi['A' + i] = i + 26;
    }

    std::cin >> num_cases;
    while (num_cases--) {
        exist.fill(false);
        table[0].child.fill(0);
        table[0].id.clear();
        table_size = 1;

        std::cin >> str;
        std::cin >> num_query;
        for (int i = 0; i < num_query; ++i) {
            std::cin >> query;
            int idx = 0;
            for (int j = 0; j < query.size(); ++j) {
                if (table[idx].child[ctoi[query[j]]] > 0) {
                    idx = table[idx].child[ctoi[query[j]]];
                }
                else {
                    table[idx].child[ctoi[query[j]]] = table_size;
                    idx                              = table_size;
                    table[idx].child.fill(0);
                    table[idx].id.clear();
                    ++table_size;
                }
            }
            table[idx].id.push_back(i);
        }

        for (int i = 0; i < str.size(); ++i) {
            int idx = 0;
            int len = 0;
            while (i + len < str.size()) {
                idx = table[idx].child[ctoi[str[i + len]]];
                if (!idx) {
                    break;
                }
                for (const auto &j : table[idx].id) {
                    exist[j] = true;
                }
                ++len;
            }
        }

        for (int i = 0; i < num_query; ++i) {
            if (exist[i])
                std::cout << "y" << std::endl;
            else
                std::cout << "n" << std::endl;
        }
    }

    return 0;
}
