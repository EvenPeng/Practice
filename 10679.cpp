#include <iostream>
#include <string>

static bool KMP_algorithm(const std::string &full, const std::string &sub)
{
    int i, j, table[1000];

    // build table
    i        = 1;
    j        = 0;
    table[0] = -1;
    while (i < sub.size()) {
        if (sub[i] == sub[j]) {
            table[i] = table[j];
        }
        else {
            table[i] = j;
            j        = table[j];
            while (j > 0 && sub[i] != sub[j])
                j = table[j];
        }
        ++i;
        ++j;
    }

    // search
    i = 0;
    j = 0;
    while (i < full.size()) {
        if (full[i] == sub[j]) {
            ++i;
            ++j;
            if (j == sub.size()) {
                return true;
            }
        }
        else {
            j = table[j];
            if (j < 0) {
                ++i;
                ++j;
            }
        }
    }

    return false;
}

int main(void)
{
    int         num_cases, num_query;
    std::string full_str, sub_str;

    std::cin >> num_cases;
    while (num_cases--) {
        std::cin >> full_str;
        std::cin >> num_query;
        for (int i = 0; i < num_query; ++i) {
            std::cin >> sub_str;
            if (KMP_algorithm(full_str, sub_str))
                std::cout << "y" << std::endl;
            else
                std::cout << "n" << std::endl;
        }
    }

    return 0;
}
