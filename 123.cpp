#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Title {
    size_t      idx;
    std::string key, full;
};

bool sort_title(const Title &x, const Title &y)
{
    auto size = x.key.size() > y.key.size() ? y.key.size() : x.key.size();
    for (int i = 0; i < size; ++i) {
        if (x.key[i] != y.key[i]) return x.key[i] < y.key[i];
    }
    return x.key.size() == y.key.size() ? x.idx < y.idx
                                        : x.key.size() < y.key.size();
}

int main(void)
{
    std::string              buffer;
    std::vector<std::string> keyword;
    std::vector<Title>       title;

    while (1) {
        getline(std::cin, buffer);
        if (buffer == "::") break;
        keyword.push_back(buffer);
    }

    size_t count = 0;
    while (getline(std::cin, buffer)) {
        std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
        size_t i = 0, j;
        do {
            j        = buffer.substr(i).find(' ');
            auto sub = buffer.substr(i, j);
            if (std::find(keyword.begin(), keyword.end(), sub) ==
                keyword.end()) {
                std::transform(sub.begin(), sub.end(), sub.begin(), ::toupper);
                title.push_back({count * 10000 + i, sub, buffer});
                for (int l = 0; l < sub.size(); ++l) {
                    title.back().full[i + l] = sub[l];
                }
            }
            i += j + 1;
        } while (j != std::string::npos);
        ++count;
    }
    std::sort(title.begin(), title.end(), sort_title);

    for (const auto &t : title) {
        std::cout << t.full << std::endl;
    }

    return 0;
}
