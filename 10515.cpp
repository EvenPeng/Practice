#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> period = {
    {0}, {1}, {2, 4, 8, 6}, {3, 9, 7, 1}, {4, 6},
    {5}, {6}, {7, 9, 3, 1}, {8, 4, 2, 6}, {9, 1}};

int main(void)
{
    int         n, m;
    std::string N, M;

    while (1) {
        std::cin >> N >> M;
        if (N.size() == 1 && N[0] == '0' && M.size() == 1 && M[0] == '0') break;
        if (M.size() == 1) {
            if (M[0] == '0') {
                std::cout << "1" << std::endl;
                continue;
            }
            else {
                m = int(M[M.size() - 1] - '0') - 1;
            }
        }
        else {
            m = (int(M[M.size() - 2] - '0') * 10 + int(M[M.size() - 1] - '0')) -
                1;
        }

        n = int(N[N.size() - 1] - '0');
        m %= period[n].size();
        std::cout << period[n][m] << std::endl;
    }

    return 0;
}
