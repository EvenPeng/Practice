#include <iostream>
#include <string>

int main(void)
{
    bool        space, same;
    int         num_case, cnt;
    std::string buffer, team, judge;

    getline(std::cin, buffer);
    num_case = std::stoi(buffer);
    for (int idx = 1; idx <= num_case; ++idx) {
        getline(std::cin, team);
        getline(std::cin, judge);
        std::cout << "Case " << idx << ": ";

        space = false;
        same  = true;
        cnt   = 0;
        for (int i = 0; i < team.size(); ++i) {
            if (team[i] == ' ') {
                space = true;
            }
            else if (cnt >= judge.size() || judge[cnt++] != team[i]) {
                same = false;
                break;
            }
        }

        if (same) same = cnt == judge.size();

        if (!same)
            std::cout << "Wrong Answer" << std::endl;
        else if (space)
            std::cout << "Output Format Error" << std::endl;
        else
            std::cout << "Yes" << std::endl;
    }

    return 0;
}
