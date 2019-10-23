#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

#define Vote int

struct People {
    Vote v[20], *p;
};

void parse_vote(People &p, std::string line)
{
    int x = 0, i = 0, j = 1;
    while (j < line.size()) {
        if (line[j] == ' ') {
            p.v[x++] = std::stoi(line.substr(i, j - i)) - 1;
            i        = j + 1;
            j        = i + 1;
        }
        else {
            ++j;
        }
    }
    p.v[x++] = std::stoi(line.substr(i, j - i)) - 1;
    p.p      = p.v;
}

void judge(Vote *sum, bool *eliminated, int num_candidate, int num_people,
           int *max_vote, int *min_vote)
{
    *min_vote = num_people;
    *max_vote = 0;
    for (int i = 0; i < num_candidate; ++i) {
        if (!eliminated[i]) {
            *min_vote = std::min(*min_vote, sum[i]);
            *max_vote = std::max(*max_vote, sum[i]);
        }
    }
}

void update_sum(Vote *sum, bool *eliminated, People *people, int num_people)
{
    for (int i = 0; i < num_people; ++i)
        if (eliminated[*people[i].p]) {
            --sum[*people[i].p];
            while (eliminated[*people[i].p])
                ++people[i].p;
            ++sum[*people[i].p];
        }
}

int main(void)
{
    int         num_cases, num_candidate, num_people, min_vote, max_vote;
    std::string buffer, candidates[20];
    People      people[1000];
    Vote        sum[20];
    bool        eliminated[20];

    std::getline(std::cin, buffer);
    num_cases = std::stoi(buffer);
    std::getline(std::cin, buffer);
    while (num_cases--) {
        std::getline(std::cin, buffer);
        num_candidate = std::stoi(buffer);
        for (int i = 0; i < num_candidate; ++i) {
            std::getline(std::cin, candidates[i]);
        }

        num_people = 0;
        while (1) {
            std::getline(std::cin, buffer);
            if (!buffer.size()) break;
            parse_vote(people[num_people++], buffer);
        }

        memset(eliminated, false, sizeof(eliminated));
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < num_people; ++i)
            ++sum[*people[i].p];

        for (int k = 0; k < num_candidate; ++k) {
            judge(sum, eliminated, num_candidate, num_people, &max_vote,
                  &min_vote);
            if (max_vote * 2 > num_people || min_vote == max_vote) break;
            for (int i = 0; i < num_candidate; ++i)
                if (sum[i] == min_vote) eliminated[i] = true;
            update_sum(sum, eliminated, people, num_people);
        }

        if (min_vote != max_vote) {
            for (int i = 0; i < num_candidate; ++i)
                if (sum[i] == max_vote) {
                    std::cout << candidates[i] << std::endl;
                    break;
                }
        }
        else {
            for (int i = 0; i < num_candidate; ++i)
                if (sum[i] == min_vote) {
                    std::cout << candidates[i] << std::endl;
                }
        }
        if (num_cases) std::cout << std::endl;
    }

    return 0;
}
