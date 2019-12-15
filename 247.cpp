#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

int num_people, num_call;

std::array<bool, 1000>                   seen;
std::array<std::array<bool, 1000>, 1000> exist;

void explore(int x)
{
    for (int i = 0; i < num_people; ++i) {
        if (!seen[i] && exist[x][i]) {
            seen[i] = true;
            explore(i);
            for (int j = 0; j < num_people; ++j)
                exist[x][j] |= exist[i][j];
        }
    }
}

int main(void)
{
    int                        case_id = 0;
    std::string                src, dst;
    std::vector<std::string>   name;
    std::map<std::string, int> name_id;
    std::array<int, 1000>      circle_id;

    while (1) {
        std::cin >> num_people >> num_call;
        if (!num_people && !num_call) break;
        if (case_id) std::cout << std::endl;

        if (!num_call) {
            std::cout << "Calling circles for data set " << ++case_id << ":"
                      << std::endl;
            continue;
        }
        for (int i = 0; i < num_people; ++i) {
            circle_id[i] = i;
            exist[i].fill(false);
        }
        name.clear();
        name_id.clear();
        for (int i = 0; i < num_call; ++i) {
            std::cin >> src >> dst;
            if (!name_id[src]) {
                name_id[src] = name_id.size();
                name.push_back(src);
            }
            if (!name_id[dst]) {
                name_id[dst] = name_id.size();
                name.push_back(dst);
            }
            exist[name_id[src] - 1][name_id[dst] - 1] = true;
        }

        for (auto i = name_id.begin(); i != name_id.end(); ++i) {
            --i->second;
        }

        for (int i = 0; i < num_people; ++i) {
            seen.fill(false);
            explore(i);
        }

        for (int i = 0; i < num_people; ++i) {
            for (int j = 0; j < num_people; ++j) {
                if (exist[i][j] && exist[j][i]) {
                    circle_id[i] = j;
                    break;
                }
            }
        }

        std::cout << "Calling circles for data set " << ++case_id << ":"
                  << std::endl;
        for (int i = 0; i < num_people; ++i) {
            if (circle_id[i] == i) {
                bool first = true;
                for (int j = 0; j < num_people; ++j) {
                    if (circle_id[j] == i) {
                        if (!first)
                            std::cout << ", ";
                        else
                            first = false;
                        std::cout << name[j];
                    }
                }
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
