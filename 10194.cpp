#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>

struct Team {
    std::string name;
    int         point, matches;
    int         win, tie, lose;
    int         goal_scored, goal_against;
};

bool sort_team(const Team &x, const Team &y)
{
    if (x.point != y.point) return x.point > y.point;
    if (x.win != y.win) return x.win > y.win;
    if (x.goal_scored - x.goal_against != y.goal_scored - y.goal_against)
        return x.goal_scored - x.goal_against > y.goal_scored - y.goal_against;
    if (x.goal_scored != y.goal_scored) return x.goal_scored > y.goal_scored;
    if (x.matches != y.matches) return x.matches < y.matches;
    for (int i = 0; i < std::min(x.name.size(), y.name.size()); ++i) {
        auto xc = tolower(x.name[i]);
        auto yc = tolower(y.name[i]);
        if (xc != yc) return xc < yc;
    }
    return x.name.size() < y.name.size();
}

int main(void)
{
    int                        num_games, num_teams, num_matches;
    std::string                buffer;
    std::string                game_name;
    Team                       team[30];
    std::map<std::string, int> team_index;
    std::string                nameA, nameB;
    int                        scoreA, scoreB;

    getline(std::cin, buffer);
    num_games = stoi(buffer);
    while (num_games--) {
        team_index.clear();
        getline(std::cin, game_name);

        getline(std::cin, buffer);
        num_teams = stoi(buffer);
        for (int i = 0; i < num_teams; ++i) {
            getline(std::cin, team[i].name);
            team_index[team[i].name] = i;
            team[i].matches          = 0;
            team[i].win              = 0;
            team[i].tie              = 0;
            team[i].lose             = 0;
            team[i].point            = 0;
            team[i].goal_scored      = 0;
            team[i].goal_against     = 0;
        }

        getline(std::cin, buffer);
        num_matches = stoi(buffer);
        for (int i = 0; i < num_matches; ++i) {
            getline(std::cin, buffer);
            int beg = 0, end = 0;
            while (buffer[++end] != '#')
                ;
            nameA = buffer.substr(beg, end - beg);
            ++end;
            beg = end;
            while (buffer[++end] != '@')
                ;
            scoreA = stoi(buffer.substr(beg, end - beg));
            ++end;
            beg = end;
            while (buffer[++end] != '#')
                ;
            scoreB = stoi(buffer.substr(beg, end - beg));
            nameB  = buffer.substr(end + 1);

            team[team_index[nameA]].matches += 1;
            team[team_index[nameB]].matches += 1;
            team[team_index[nameA]].goal_scored += scoreA;
            team[team_index[nameB]].goal_scored += scoreB;
            team[team_index[nameA]].goal_against += scoreB;
            team[team_index[nameB]].goal_against += scoreA;
            if (scoreA < scoreB) {
                team[team_index[nameA]].lose += 1;
                team[team_index[nameB]].win += 1;
                team[team_index[nameB]].point += 3;
            }
            else if (scoreA > scoreB) {
                team[team_index[nameA]].win += 1;
                team[team_index[nameB]].lose += 1;
                team[team_index[nameA]].point += 3;
            }
            else {
                team[team_index[nameA]].tie += 1;
                team[team_index[nameB]].tie += 1;
                team[team_index[nameA]].point += 1;
                team[team_index[nameB]].point += 1;
            }
        }
        std::sort(team, team + num_teams, sort_team);

        std::cout << game_name << std::endl;
        for (int i = 0; i < num_teams; ++i) {
            std::cout << i + 1 << ") " << team[i].name << " " << team[i].point
                      << "p, " << team[i].matches << "g "
                      << "(" << team[i].win << "-" << team[i].tie << "-"
                      << team[i].lose << "), "
                      << team[i].goal_scored - team[i].goal_against << "gd "
                      << "(" << team[i].goal_scored << "-"
                      << team[i].goal_against << ")" << std::endl;
        }
        if (num_games) std::cout << std::endl;
    }

    return 0;
}
