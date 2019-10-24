#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>

struct Edge {
    int x, y;
};

int              num_words;
int              steps[201][201];
std::queue<Edge> edges;

bool one_step(std::string &x, std::string &y)
{
    if (x.size() != y.size()) return false;
    int diff = 0;
    for (int i = 0; i < x.size(); ++i)
        if (x[i] != y[i]) ++diff;
    return diff == 1;
}

void explore()
{
    while (!edges.empty()) {
        Edge e = edges.front();
        edges.pop();
        for (int i = 0; i < num_words; ++i) {
            if (i != e.x && i != e.y) {
                if (steps[e.y][i] &&
                    (!steps[e.x][i] ||
                     steps[e.x][e.y] + steps[e.y][i] < steps[e.x][i])) {
                    steps[e.x][i] = steps[e.x][e.y] + steps[e.y][i];
                    steps[i][e.x] = steps[e.x][i];
                    edges.push({e.x, i});
                }
                if (steps[i][e.x] &&
                    (!steps[i][e.y] ||
                     steps[i][e.x] + steps[e.x][e.y] < steps[i][e.y])) {
                    steps[i][e.y] = steps[i][e.x] + steps[e.x][e.y];
                    steps[e.y][i] = steps[i][e.y];
                    edges.push({i, e.y});
                }
            }
        }
    }
}

int main(void)
{
    int                        num_cases;
    std::string                buffer;
    std::string                words[201];
    std::map<std::string, int> dictionary;

    getline(std::cin, buffer);
    num_cases = std::stoi(buffer);

    getline(std::cin, buffer);
    for (int k = 0; k < num_cases; ++k) {
        if (k) std::cout << std::endl;
        dictionary.clear();
        num_words = 0;
        while (1) {
            getline(std::cin, words[num_words]);
            if (words[num_words][0] == '*') break;
            dictionary[words[num_words]] = num_words;

            memset(steps[num_words], 0, sizeof(steps[num_words]));
            for (int i = 0; i < num_words; ++i)
                if (one_step(words[i], words[num_words])) {
                    steps[i][num_words] = 1;
                    steps[num_words][i] = 1;
                    edges.push({i, num_words});
                }
            ++num_words;
        }

        explore();

        while (1) {
            getline(std::cin, buffer);
            if (!buffer.size()) break;
            auto split = buffer.find(" ");
            std::cout << buffer << " "
                      << steps[dictionary[buffer.substr(0, split)]]
                              [dictionary[buffer.substr(split + 1)]]
                      << std::endl;
        }
    }

    return 0;
}
